#!/bin/bash

func1()
{
	local var='func1 local'
	func2
}

func2()
{
	unset var
	echo "In fun2, var = $var"
}

func1
declare -F
