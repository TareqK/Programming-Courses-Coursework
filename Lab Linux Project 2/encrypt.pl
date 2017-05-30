#Lab linux project
#Tareq Kirresh
#1142828
#Mahmoud Abufarha
#1131014
#Project Codename:Encryptorinator 9000
#بسم الله الرحمن الرحيم

#!/usr/bin/perl

sub even{#same as even in decrypt, since even and odd are inverses of eachother{ #same as the function for odd in decrypt , since even and odd are inverses of eachoter
$file2=$ARGV[0].''."_ENCRYPTED";

open (my $info2, '>>', $file2) or die "Could not open $file: $!";
foreach $string (@_){	
@words = split(" ", $string);#split the sentence into words
$wordsize=@words;

for($i=0;$i<$wordsize;$i++)
{
	if((i+1)%2==1){
	$key=$i+1;
	$tkey;
	@char=split("",$words[$i]);
	$charsize=@char;
	for($j=0;$j<$charsize;$j++)
	{
		
		if(ord('A')<=ord($char[$j])&&ord($char[$j])<=ord('Z'))
		{
			
			$temp=ord($char[$j])+$key;
			$tkey=$key;
			if($temp>ord('Z'))
			{
				$tkey=$tkey-(ord('Z')-ord($char[$j]))-1;
				$tkey=$tkey%26;
				$temp=ord('A')+$tkey;
			}
			$char[$j]=chr($temp);
		
			$key=$key+1;
		}
		
		else 
		{if(ord('a')<=ord($char[$j])&&ord($char[$j])<=ord('z'))
		{
			
			$temp=ord($char[$j])+$key;
			$tkey=$key;
			if($temp>ord('z'))
			{
				
				$tkey=$tkey-(ord('z')-ord($char[$j]))-1;
				$tkey=$tkey%26;
				$temp=ord('a')+$tkey;
			
			}
			
			$char[$j]=chr($temp);
			
			$key=$key+1;
		}
	}
	print $info2 "$char[$j]";#print the char	
	}

	print $info2 " ";
}


else
{
	$key=-$i-1;
	$tkey;
	@char=split("",$words[$i]);
	$charsize=@char;
	for($j=0;$j<$charsize;$j++)
	{
		
		if(ord('A')<=ord($char[$j])&&ord($char[$j])<=ord('Z'))
		{
			
			$temp=ord($char[$j])+$key;
			$tkey=$key;
			if($temp<ord('A'))
			{
				$tkey=$tkey+(ord($char[$j])-ord('A'))+1;
				$tkey=$tkey%-26;
				$temp=ord('Z')+$tkey;
			}
			$char[$j]=chr($temp);

			$key=$key-1;
		}
		
		else 
		{if(ord('a')<=ord($char[$j])&&ord($char[$j])<=ord('z'))
		{
			
			$temp=ord($char[$j])+$key;
			$tkey=$key;
			if($temp<ord('a'))
			{
				$tkey=$tkey+(ord($char[$j])-ord('a'))+1;
				$tkey=$tkey%-26;
				$temp=ord('z')+$tkey;
			}
			
			$char[$j]=chr($temp);
			
			$key=$key-1;
		}
	}
	print $info2 "$char[$j]";#print the char	
}
	
	print $info2 " ";
}

	
}

}
print $info2 "\n";
close $info2;
}


sub odd{#same as even in decrypt, since even and odd are inverses of eachother{ #same as the function for odd in decrypt , since even and odd are inverses of eachoter
$file2=$ARGV[0].''."_ENCRYPTED";

open (my $info3, '>>', $file2) or die "Could not open $file: $!";
foreach $string (@_){	
@words = split(" ", $string);#split the sentence into words
$wordsize=@words;

for($i=0;$i<$wordsize;$i++)
{
	if((i+1)%2==0){
	$key=$i+1;
	$tkey;
	@char=split("",$words[$i]);
	$charsize=@char;
	
	
	for($j=0;$j<$charsize;$j++)
	{
		
		if(ord('A')<=ord($char[$j])&&ord($char[$j])<=ord('Z'))
		{
			
			$temp=ord($char[$j])+$key;
			$tkey=$key;
			if($temp>ord('Z'))
			{
				$tkey=$tkey-(ord('Z')-ord($char[$j]))-1;
				$tkey=$tkey%26;
				$temp=ord('A')+$tkey;
			}
			$char[$j]=chr($temp);
		
			$key=$key+1;
		}
		
		else 
		{if(ord('a')<=ord($char[$j])&&ord($char[$j])<=ord('z'))
		{
			
			$temp=ord($char[$j])+$key;
			$tkey=$key;
			if($temp>ord('z'))
			{
				
				$tkey=$tkey-(ord('z')-ord($char[$j]))-1;
				$tkey=$tkey%26;
				$temp=ord('a')+$tkey;
			
			}
			
			$char[$j]=chr($temp);
			
			$key=$key+1;
		}
	}
	print $info3 "$char[$j]";#print the char	
	}

	print $info3 " ";
}


else
{
	$key=-$i-1;
	
	$tkey;
	@char=split("",$words[$i]);
	$charsize=@char;
	for($j=0;$j<$charsize;$j++)
	{
		
		if(ord('A')<=ord($char[$j])&&ord($char[$j])<=ord('Z'))
		{
			
			$temp=ord($char[$j])+$key;
			$tkey=$key;
			if($temp<ord('A'))
			{
				$tkey=$tkey+(ord($char[$j])-ord('A'))+1;
				$tkey=$tkey%-26;
				$temp=ord('Z')+$tkey;
			}
			$char[$j]=chr($temp);

			$key=$key-1;
		}
		
		else 
		{if(ord('a')<=ord($char[$j])&&ord($char[$j])<=ord('z'))
		{
			
			$temp=ord($char[$j])+$key;
			$tkey=$key;
			if($temp<ord('a'))
			{
				$tkey=$tkey+(ord($char[$j])-ord('a'))+1;
				$tkey=$tkey%-26;
				$temp=ord('z')+$tkey;
			}
			
			$char[$j]=chr($temp);
			
			$key=$key-1;
		}
	}
	print $info3 "$char[$j]";#print the char	
}
	
	print $info3 " ";
}

	
}

	
}
print $info3 "\n";
close $info3;
}

my $file = $ARGV[0];#taking commandline arguments

open my $info, $file or die "Could not open $file: $!";
my $count = 1;
while( my $line = <$info>)  {   
    if($count%2!=0)
    {
		odd($line);

	}
	else
	{
		even($line);

	}
	$count++;
	
	
}
close $info;
