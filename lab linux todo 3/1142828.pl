$name1 = <STDIN>;
chomp($name1);
$name2 = reverse($name1);
if($name1 eq $name2)
{
	print("$name2 Is palindrome\n");
	exit;
}
print("$name2 Not palindrome\n");

