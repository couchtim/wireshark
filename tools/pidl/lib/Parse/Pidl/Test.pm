# Simple system for running tests against pidl
# (C) 2005 Jelmer Vernooij <jelmer@samba.org>
# Published under the GNU General Public License

package Parse::Pidl::Test;

use strict;
use Parse::Pidl::Util;
use Getopt::Long;

my $cc = $ENV{CC};
my @cflags = split / /, $ENV{CFLAGS};
my @ldflags = split / /, $ENV{LDFLAGS};

$cc = "cc" if ($cc eq "");

sub generate_cfile($$$)
{
	my ($filename, $fragment, $incfiles) = @_;

	unless (open (OUT, ">$filename")) {
		print STDERR "Unable to open $filename\n";
		return -1;
	}
	print OUT '
/* This file was autogenerated. All changes made will be lost! */
#include "include/includes.h"
';

	foreach (@$incfiles) {
		print OUT "#include \"$_\"\n";
	}

	print OUT '
int main(int argc, char **argv)
{
	TALLOC_CTX *mem_ctx = talloc_init(NULL);
	';
	print OUT $fragment;
	print OUT "\treturn 0;\n}\n";
	close OUT;

	return 0;
}

sub generate_idlfile($$)
{
	my ($filename,$fragment) = @_;

	unless (open(OUT, ">$filename")) {
		print STDERR "Unable to open $filename\n";
		return -1;
	}
	
	print OUT '
[uuid("1-2-3-4-5")] interface test_if
{
';
	print OUT $fragment;
	print OUT "\n}\n";
	close OUT;

	return 0;
}

sub compile_idl($$$)
{
	my ($filename,$idl_path, $idlargs) = @_;

	my @args = @$idlargs;
	push (@args, $filename);

	unless (system($idl_path, @args) == 0) {
		print STDERR "Error compiling IDL file $filename: $!\n";
		return -1;
	}
}

sub compile_cfile($)
{
	my ($filename) = @_;

	return system($cc, @cflags, '-I.', '-Iinclude', '-c', $filename);
}

sub link_files($$)
{
	my ($exe_name,$objs) = @_;

	return system($cc, @ldflags, '-Lbin', '-lrpc', '-o', $exe_name, @$objs);
}

sub test_idl($$$$)
{
	my ($name,$settings,$idl,$c) = @_;

	$| = 1;

	print "Running $name... ";

	my $outputdir = $settings->{OutputDir};

	my $c_filename = $outputdir."/".$name."_test.c";
	my $idl_filename = $outputdir."/".$name."_idl.idl";
	my $exe_filename = $outputdir."/".$name."_exe";

	return -1 if (generate_cfile($c_filename, $c, $settings->{IncludeFiles}) == -1);

	return -1 if (generate_idlfile($idl_filename, $idl) == -1);

	return -1 if (compile_idl($idl_filename, $settings->{'IDL-Compiler'}, $settings->{'IDL-Arguments'}) == -1);

	my @srcs = ($c_filename);
	push (@srcs, @{$settings->{'ExtraFiles'}});

	foreach (@srcs) {
		next unless /\.c$/;
		return -1 if (compile_cfile($_) == -1);
	}

	my @objs;
	foreach (@srcs) {
		if (/\.c$/) { s/\.c$/\.o/g; }
		push(@objs, $_);
	}

	return -1 if (link_files($exe_filename, \@objs) == -1);

	my $ret = system("./$exe_filename");
	if ($ret != 0) {
		$ret = $? >> 8;
		print "failed with return value $ret\n";
		return $ret;
	}

	unless ($settings->{Keep}) {
		unlink(@srcs, @objs, $exe_filename, $idl_filename);
	}

	print "Ok\n";

	return $ret;
}

sub GetSettings($)
{
	my $settings = { 
		OutputDir => ".",
		'IDL-Compiler' => "./pidl"
	};

	my %opts = ();
	GetOptions('idl-compiler=s' => \$settings->{'IDL-Compiler'},
		'outputdir=s' => \$settings->{OutputDir},
		'keep' => \$settings->{Keep},
		'help' => sub { ShowHelp(); exit 1; } );

	return %$settings;
}

sub ShowHelp()
{
	print " --idl-compiler=PATH-TO-PIDL  Override path to IDL compiler\n";
	print " --outputdir=OUTPUTDIR        Write temporary files to OUTPUTDIR rather then .\n";
	print " --keep                       Keep intermediate files after running test";
	print " --help                       Show this help message\n";
}

1;
