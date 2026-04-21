
bomb：     文件格式 elf32-i386


Disassembly of section .init:

08048528 <_init>:
 8048528:	53                   	push   %ebx
 8048529:	83 ec 08             	sub    $0x8,%esp
 804852c:	e8 4f 01 00 00       	call   8048680 <__x86.get_pc_thunk.bx>
 8048531:	81 c3 cf 2a 00 00    	add    $0x2acf,%ebx
 8048537:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 804853d:	85 c0                	test   %eax,%eax
 804853f:	74 05                	je     8048546 <_init+0x1e>
 8048541:	e8 8a 00 00 00       	call   80485d0 <__gmon_start__@plt>
 8048546:	83 c4 08             	add    $0x8,%esp
 8048549:	5b                   	pop    %ebx
 804854a:	c3                   	ret

Disassembly of section .plt:

08048550 <.plt>:
 8048550:	ff 35 04 b0 04 08    	push   0x804b004
 8048556:	ff 25 08 b0 04 08    	jmp    *0x804b008
 804855c:	00 00                	add    %al,(%eax)
	...

08048560 <fflush@plt>:
 8048560:	ff 25 0c b0 04 08    	jmp    *0x804b00c
 8048566:	68 00 00 00 00       	push   $0x0
 804856b:	e9 e0 ff ff ff       	jmp    8048550 <.plt>

08048570 <fgets@plt>:
 8048570:	ff 25 10 b0 04 08    	jmp    *0x804b010
 8048576:	68 08 00 00 00       	push   $0x8
 804857b:	e9 d0 ff ff ff       	jmp    8048550 <.plt>

08048580 <signal@plt>:
 8048580:	ff 25 14 b0 04 08    	jmp    *0x804b014
 8048586:	68 10 00 00 00       	push   $0x10
 804858b:	e9 c0 ff ff ff       	jmp    8048550 <.plt>

08048590 <sleep@plt>:
 8048590:	ff 25 18 b0 04 08    	jmp    *0x804b018
 8048596:	68 18 00 00 00       	push   $0x18
 804859b:	e9 b0 ff ff ff       	jmp    8048550 <.plt>

080485a0 <__stack_chk_fail@plt>:
 80485a0:	ff 25 1c b0 04 08    	jmp    *0x804b01c
 80485a6:	68 20 00 00 00       	push   $0x20
 80485ab:	e9 a0 ff ff ff       	jmp    8048550 <.plt>

080485b0 <getenv@plt>:
 80485b0:	ff 25 20 b0 04 08    	jmp    *0x804b020
 80485b6:	68 28 00 00 00       	push   $0x28
 80485bb:	e9 90 ff ff ff       	jmp    8048550 <.plt>

080485c0 <puts@plt>:
 80485c0:	ff 25 24 b0 04 08    	jmp    *0x804b024
 80485c6:	68 30 00 00 00       	push   $0x30
 80485cb:	e9 80 ff ff ff       	jmp    8048550 <.plt>

080485d0 <__gmon_start__@plt>:
 80485d0:	ff 25 28 b0 04 08    	jmp    *0x804b028
 80485d6:	68 38 00 00 00       	push   $0x38
 80485db:	e9 70 ff ff ff       	jmp    8048550 <.plt>

080485e0 <exit@plt>:
 80485e0:	ff 25 2c b0 04 08    	jmp    *0x804b02c
 80485e6:	68 40 00 00 00       	push   $0x40
 80485eb:	e9 60 ff ff ff       	jmp    8048550 <.plt>

080485f0 <__libc_start_main@plt>:
 80485f0:	ff 25 30 b0 04 08    	jmp    *0x804b030
 80485f6:	68 48 00 00 00       	push   $0x48
 80485fb:	e9 50 ff ff ff       	jmp    8048550 <.plt>

08048600 <__isoc99_sscanf@plt>:
 8048600:	ff 25 34 b0 04 08    	jmp    *0x804b034
 8048606:	68 50 00 00 00       	push   $0x50
 804860b:	e9 40 ff ff ff       	jmp    8048550 <.plt>

08048610 <fopen@plt>:
 8048610:	ff 25 38 b0 04 08    	jmp    *0x804b038
 8048616:	68 58 00 00 00       	push   $0x58
 804861b:	e9 30 ff ff ff       	jmp    8048550 <.plt>

08048620 <__printf_chk@plt>:
 8048620:	ff 25 3c b0 04 08    	jmp    *0x804b03c
 8048626:	68 60 00 00 00       	push   $0x60
 804862b:	e9 20 ff ff ff       	jmp    8048550 <.plt>

08048630 <strtol@plt>:
 8048630:	ff 25 40 b0 04 08    	jmp    *0x804b040
 8048636:	68 68 00 00 00       	push   $0x68
 804863b:	e9 10 ff ff ff       	jmp    8048550 <.plt>

08048640 <__ctype_b_loc@plt>:
 8048640:	ff 25 44 b0 04 08    	jmp    *0x804b044
 8048646:	68 70 00 00 00       	push   $0x70
 804864b:	e9 00 ff ff ff       	jmp    8048550 <.plt>

Disassembly of section .text:

08048650 <_start>:
 8048650:	31 ed                	xor    %ebp,%ebp
 8048652:	5e                   	pop    %esi
 8048653:	89 e1                	mov    %esp,%ecx
 8048655:	83 e4 f0             	and    $0xfffffff0,%esp
 8048658:	50                   	push   %eax
 8048659:	54                   	push   %esp
 804865a:	52                   	push   %edx
 804865b:	68 c0 90 04 08       	push   $0x80490c0
 8048660:	68 50 90 04 08       	push   $0x8049050
 8048665:	51                   	push   %ecx
 8048666:	56                   	push   %esi
 8048667:	68 4d 87 04 08       	push   $0x804874d
 804866c:	e8 7f ff ff ff       	call   80485f0 <__libc_start_main@plt>
 8048671:	f4                   	hlt
 8048672:	66 90                	xchg   %ax,%ax
 8048674:	66 90                	xchg   %ax,%ax
 8048676:	66 90                	xchg   %ax,%ax
 8048678:	66 90                	xchg   %ax,%ax
 804867a:	66 90                	xchg   %ax,%ax
 804867c:	66 90                	xchg   %ax,%ax
 804867e:	66 90                	xchg   %ax,%ax

08048680 <__x86.get_pc_thunk.bx>:
 8048680:	8b 1c 24             	mov    (%esp),%ebx
 8048683:	c3                   	ret
 8048684:	66 90                	xchg   %ax,%ax
 8048686:	66 90                	xchg   %ax,%ax
 8048688:	66 90                	xchg   %ax,%ax
 804868a:	66 90                	xchg   %ax,%ax
 804868c:	66 90                	xchg   %ax,%ax
 804868e:	66 90                	xchg   %ax,%ax

08048690 <deregister_tm_clones>:
 8048690:	b8 83 b3 04 08       	mov    $0x804b383,%eax
 8048695:	2d 80 b3 04 08       	sub    $0x804b380,%eax
 804869a:	83 f8 06             	cmp    $0x6,%eax
 804869d:	77 01                	ja     80486a0 <deregister_tm_clones+0x10>
 804869f:	c3                   	ret
 80486a0:	b8 00 00 00 00       	mov    $0x0,%eax
 80486a5:	85 c0                	test   %eax,%eax
 80486a7:	74 f6                	je     804869f <deregister_tm_clones+0xf>
 80486a9:	55                   	push   %ebp
 80486aa:	89 e5                	mov    %esp,%ebp
 80486ac:	83 ec 18             	sub    $0x18,%esp
 80486af:	c7 04 24 80 b3 04 08 	movl   $0x804b380,(%esp)
 80486b6:	ff d0                	call   *%eax
 80486b8:	c9                   	leave
 80486b9:	c3                   	ret
 80486ba:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

080486c0 <register_tm_clones>:
 80486c0:	b8 80 b3 04 08       	mov    $0x804b380,%eax
 80486c5:	2d 80 b3 04 08       	sub    $0x804b380,%eax
 80486ca:	c1 f8 02             	sar    $0x2,%eax
 80486cd:	89 c2                	mov    %eax,%edx
 80486cf:	c1 ea 1f             	shr    $0x1f,%edx
 80486d2:	01 d0                	add    %edx,%eax
 80486d4:	d1 f8                	sar    $1,%eax
 80486d6:	75 01                	jne    80486d9 <register_tm_clones+0x19>
 80486d8:	c3                   	ret
 80486d9:	ba 00 00 00 00       	mov    $0x0,%edx
 80486de:	85 d2                	test   %edx,%edx
 80486e0:	74 f6                	je     80486d8 <register_tm_clones+0x18>
 80486e2:	55                   	push   %ebp
 80486e3:	89 e5                	mov    %esp,%ebp
 80486e5:	83 ec 18             	sub    $0x18,%esp
 80486e8:	89 44 24 04          	mov    %eax,0x4(%esp)
 80486ec:	c7 04 24 80 b3 04 08 	movl   $0x804b380,(%esp)
 80486f3:	ff d2                	call   *%edx
 80486f5:	c9                   	leave
 80486f6:	c3                   	ret
 80486f7:	89 f6                	mov    %esi,%esi
 80486f9:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

08048700 <__do_global_dtors_aux>:
 8048700:	80 3d a4 b3 04 08 00 	cmpb   $0x0,0x804b3a4
 8048707:	75 13                	jne    804871c <__do_global_dtors_aux+0x1c>
 8048709:	55                   	push   %ebp
 804870a:	89 e5                	mov    %esp,%ebp
 804870c:	83 ec 08             	sub    $0x8,%esp
 804870f:	e8 7c ff ff ff       	call   8048690 <deregister_tm_clones>
 8048714:	c6 05 a4 b3 04 08 01 	movb   $0x1,0x804b3a4
 804871b:	c9                   	leave
 804871c:	f3 c3                	repz ret
 804871e:	66 90                	xchg   %ax,%ax

08048720 <frame_dummy>:
 8048720:	a1 10 af 04 08       	mov    0x804af10,%eax
 8048725:	85 c0                	test   %eax,%eax
 8048727:	74 1f                	je     8048748 <frame_dummy+0x28>
 8048729:	b8 00 00 00 00       	mov    $0x0,%eax
 804872e:	85 c0                	test   %eax,%eax
 8048730:	74 16                	je     8048748 <frame_dummy+0x28>
 8048732:	55                   	push   %ebp
 8048733:	89 e5                	mov    %esp,%ebp
 8048735:	83 ec 18             	sub    $0x18,%esp
 8048738:	c7 04 24 10 af 04 08 	movl   $0x804af10,(%esp)
 804873f:	ff d0                	call   *%eax
 8048741:	c9                   	leave
 8048742:	e9 79 ff ff ff       	jmp    80486c0 <register_tm_clones>
 8048747:	90                   	nop
 8048748:	e9 73 ff ff ff       	jmp    80486c0 <register_tm_clones>

0804874d <main>:
 804874d:	55                   	push   %ebp
 804874e:	89 e5                	mov    %esp,%ebp
 8048750:	53                   	push   %ebx
 8048751:	83 e4 f0             	and    $0xfffffff0,%esp
 8048754:	83 ec 10             	sub    $0x10,%esp
 8048757:	8b 45 08             	mov    0x8(%ebp),%eax
 804875a:	8b 5d 0c             	mov    0xc(%ebp),%ebx
 804875d:	83 f8 01             	cmp    $0x1,%eax
 8048760:	75 0c                	jne    804876e <main+0x21>
 8048762:	a1 80 b3 04 08       	mov    0x804b380,%eax
 8048767:	a3 ac b3 04 08       	mov    %eax,0x804b3ac
 804876c:	eb 74                	jmp    80487e2 <main+0x95>
 804876e:	83 f8 02             	cmp    $0x2,%eax
 8048771:	75 49                	jne    80487bc <main+0x6f>
 8048773:	c7 44 24 04 e8 90 04 	movl   $0x80490e8,0x4(%esp)
 804877a:	08 
 804877b:	8b 43 04             	mov    0x4(%ebx),%eax
 804877e:	89 04 24             	mov    %eax,(%esp)
 8048781:	e8 8a fe ff ff       	call   8048610 <fopen@plt>
 8048786:	a3 ac b3 04 08       	mov    %eax,0x804b3ac
 804878b:	85 c0                	test   %eax,%eax
 804878d:	75 53                	jne    80487e2 <main+0x95>
 804878f:	8b 43 04             	mov    0x4(%ebx),%eax
 8048792:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8048796:	8b 03                	mov    (%ebx),%eax
 8048798:	89 44 24 08          	mov    %eax,0x8(%esp)
 804879c:	c7 44 24 04 ea 90 04 	movl   $0x80490ea,0x4(%esp)
 80487a3:	08 
 80487a4:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 80487ab:	e8 70 fe ff ff       	call   8048620 <__printf_chk@plt>
 80487b0:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 80487b7:	e8 24 fe ff ff       	call   80485e0 <exit@plt>
 80487bc:	8b 03                	mov    (%ebx),%eax
 80487be:	89 44 24 08          	mov    %eax,0x8(%esp)
 80487c2:	c7 44 24 04 07 91 04 	movl   $0x8049107,0x4(%esp)
 80487c9:	08 
 80487ca:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 80487d1:	e8 4a fe ff ff       	call   8048620 <__printf_chk@plt>
 80487d6:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 80487dd:	e8 fe fd ff ff       	call   80485e0 <exit@plt>
 80487e2:	e8 af 05 00 00       	call   8048d96 <initialize_bomb>
 80487e7:	c7 04 24 6c 91 04 08 	movl   $0x804916c,(%esp)
 80487ee:	e8 cd fd ff ff       	call   80485c0 <puts@plt>
 80487f3:	c7 04 24 a8 91 04 08 	movl   $0x80491a8,(%esp)
 80487fa:	e8 c1 fd ff ff       	call   80485c0 <puts@plt>
 80487ff:	e8 a8 06 00 00       	call   8048eac <read_line>
 8048804:	89 04 24             	mov    %eax,(%esp)
 8048807:	e8 b4 00 00 00       	call   80488c0 <phase_1>
 804880c:	e8 95 07 00 00       	call   8048fa6 <phase_defused>
 8048811:	c7 04 24 d4 91 04 08 	movl   $0x80491d4,(%esp)
 8048818:	e8 a3 fd ff ff       	call   80485c0 <puts@plt>
 804881d:	e8 8a 06 00 00       	call   8048eac <read_line>
 8048822:	89 04 24             	mov    %eax,(%esp)
 8048825:	e8 ba 00 00 00       	call   80488e4 <phase_2>
 804882a:	e8 77 07 00 00       	call   8048fa6 <phase_defused>
 804882f:	c7 04 24 21 91 04 08 	movl   $0x8049121,(%esp)
 8048836:	e8 85 fd ff ff       	call   80485c0 <puts@plt>
 804883b:	e8 6c 06 00 00       	call   8048eac <read_line>
 8048840:	89 04 24             	mov    %eax,(%esp)
 8048843:	e8 f2 00 00 00       	call   804893a <phase_3>
 8048848:	e8 59 07 00 00       	call   8048fa6 <phase_defused>
 804884d:	c7 04 24 3f 91 04 08 	movl   $0x804913f,(%esp)
 8048854:	e8 67 fd ff ff       	call   80485c0 <puts@plt>
 8048859:	e8 4e 06 00 00       	call   8048eac <read_line>
 804885e:	89 04 24             	mov    %eax,(%esp)
 8048861:	e8 b2 01 00 00       	call   8048a18 <phase_4>
 8048866:	e8 3b 07 00 00       	call   8048fa6 <phase_defused>
 804886b:	c7 04 24 00 92 04 08 	movl   $0x8049200,(%esp)
 8048872:	e8 49 fd ff ff       	call   80485c0 <puts@plt>
 8048877:	e8 30 06 00 00       	call   8048eac <read_line>
 804887c:	89 04 24             	mov    %eax,(%esp)
 804887f:	e8 f4 01 00 00       	call   8048a78 <phase_5>
 8048884:	e8 1d 07 00 00       	call   8048fa6 <phase_defused>
 8048889:	c7 04 24 4e 91 04 08 	movl   $0x804914e,(%esp)
 8048890:	e8 2b fd ff ff       	call   80485c0 <puts@plt>
 8048895:	e8 12 06 00 00       	call   8048eac <read_line>
 804889a:	89 04 24             	mov    %eax,(%esp)
 804889d:	e8 4a 02 00 00       	call   8048aec <phase_6>
 80488a2:	e8 ff 06 00 00       	call   8048fa6 <phase_defused>
 80488a7:	b8 00 00 00 00       	mov    $0x0,%eax
 80488ac:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 80488af:	c9                   	leave
 80488b0:	c3                   	ret
 80488b1:	66 90                	xchg   %ax,%ax
 80488b3:	66 90                	xchg   %ax,%ax
 80488b5:	66 90                	xchg   %ax,%ax
 80488b7:	66 90                	xchg   %ax,%ax
 80488b9:	66 90                	xchg   %ax,%ax
 80488bb:	66 90                	xchg   %ax,%ax
 80488bd:	66 90                	xchg   %ax,%ax
 80488bf:	90                   	nop

080488c0 <phase_1>:
 80488c0:	83 ec 1c             	sub    $0x1c,%esp
 80488c3:	c7 44 24 04 24 92 04 	movl   $0x8049224,0x4(%esp)
 80488ca:	08 
 80488cb:	8b 44 24 20          	mov    0x20(%esp),%eax
 80488cf:	89 04 24             	mov    %eax,(%esp)
 80488d2:	e8 53 04 00 00       	call   8048d2a <strings_not_equal>
 80488d7:	85 c0                	test   %eax,%eax							# 等于1，炸弹爆炸
 80488d9:	74 05                	je     80488e0 <phase_1+0x20>
 80488db:	e8 55 05 00 00       	call   8048e35 <explode_bomb>
 80488e0:	83 c4 1c             	add    $0x1c,%esp
 80488e3:	c3                   	ret

080488e4 <phase_2>:
 # 构建栈帧
 80488e4:	56                   	push   %esi
 80488e5:	53                   	push   %ebx
 80488e6:	83 ec 34             	sub    $0x34,%esp
 # 准备read_six_number的参数
 80488e9:	8d 44 24 18          	lea    0x18(%esp),%eax
 80488ed:	89 44 24 04          	mov    %eax,0x4(%esp)
 80488f1:	8b 44 24 40          	mov    0x40(%esp),%eax
 80488f5:	89 04 24             	mov    %eax,(%esp)
 80488f8:	e8 5f 05 00 00       	call   8048e5c <read_six_numbers>
 # 判断前两个数字是否满足要求 
 80488fd:	83 7c 24 18 00       	cmpl   $0x0,0x18(%esp)				# arr[1]
 8048902:	75 07                	jne    804890b <phase_2+0x27>		# arr[1]=0,否则爆炸
 8048904:	83 7c 24 1c 01       	cmpl   $0x1,0x1c(%esp)				# arr[2]
 8048909:	74 1f                	je     804892a <phase_2+0x46>		# arr[2]=1,否则爆炸
 804890b:	e8 25 05 00 00       	call   8048e35 <explode_bomb>
 8048910:	eb 18                	jmp    804892a <phase_2+0x46>		# arr[1]和arr[2]都满足条件，跳入到循环
 # 循环主体
 8048912:	8b 43 f8             	mov    -0x8(%ebx),%eax				# %eax=arr[i-2]
 8048915:	03 43 fc             	add    -0x4(%ebx),%eax				# %eax=arr[i-1]+arr[i-2]
 8048918:	39 03                	cmp    %eax,(%ebx)					# arr[i]是否等于arr[i-1]+arr[i-2],不等则爆炸
 804891a:	74 05                	je     8048921 <phase_2+0x3d>		
 804891c:	e8 14 05 00 00       	call   8048e35 <explode_bomb>
 8048921:	83 c3 04             	add    $0x4,%ebx					# %ebx=&arr[++i]
 8048924:	39 f3                	cmp    %esi,%ebx					# 循环条件,当%ebx==&arr[7]时循环结束
 8048926:	75 ea                	jne    8048912 <phase_2+0x2e>		# 循环未结束
 8048928:	eb 0a                	jmp    8048934 <phase_2+0x50>		# 循环结束跳出循环
 804892a:	8d 5c 24 20          	lea    0x20(%esp),%ebx				# %ebx=&arr[i],i初始化为3
 804892e:	8d 74 24 30          	lea    0x30(%esp),%esi				# %esi=&arr[7],用来指示循环是否要结束 
 8048932:	eb de                	jmp    8048912 <phase_2+0x2e>
 # 循环结束销毁栈帧
 8048934:	83 c4 34             	add    $0x34,%esp
 8048937:	5b                   	pop    %ebx
 8048938:	5e                   	pop    %esi
 8048939:	c3                   	ret

0804893a <phase_3>:
# 建立栈帧
 804893a:	83 ec 2c             	sub    $0x2c,%esp
# 准备sscanf的参数
 804893d:	8d 44 24 1c          	lea    0x1c(%esp),%eax
 8048941:	89 44 24 0c          	mov    %eax,0xc(%esp)					# 第四个参数，我们输入的第二个数据
 8048945:	8d 44 24 18          	lea    0x18(%esp),%eax
 8048949:	89 44 24 08          	mov    %eax,0x8(%esp)					# 第三个参数，我们输入的第一个数据
 804894d:	c7 44 24 04 f1 93 04 	movl   $0x80493f1,0x4(%esp)				# 第二个参数 "%d %d"
 8048954:	08 
 8048955:	8b 44 24 30          	mov    0x30(%esp),%eax
 8048959:	89 04 24             	mov    %eax,(%esp)						# 第一个参数，我们输入的字符串
 804895c:	e8 9f fc ff ff       	call   8048600 <__isoc99_sscanf@plt>
# 判断输入值是否合法（是否输入两个整数）
 8048961:	83 f8 01             	cmp    $0x1,%eax						# %eax为sscanf返回的输入个数
 8048964:	7f 05                	jg     804896b <phase_3+0x31>
 8048966:	e8 ca 04 00 00       	call   8048e35 <explode_bomb>			# 输入不合法爆炸
# 判断输入的第一个值是否小于7
 804896b:	83 7c 24 18 07       	cmpl   $0x7,0x18(%esp)
 8048970:	77 3c                	ja     80489ae <phase_3+0x74>			# 大于7发生爆炸
# 根据跳转表和第一个参数找到对应值
 8048972:	8b 44 24 18          	mov    0x18(%esp),%eax
 8048976:	ff 24 85 80 92 04 08 	jmp    *0x8049280(,%eax,4)
 804897d:	b8 45 03 00 00       	mov    $0x345,%eax						# case(0)
 8048982:	eb 3b                	jmp    80489bf <phase_3+0x85>
 8048984:	b8 0f 02 00 00       	mov    $0x20f,%eax						# case(2)
 8048989:	eb 34                	jmp    80489bf <phase_3+0x85>
 804898b:	b8 24 02 00 00       	mov    $0x224,%eax						# case(3)
 8048990:	eb 2d                	jmp    80489bf <phase_3+0x85>
 8048992:	b8 91 03 00 00       	mov    $0x391,%eax						# case(4)
 8048997:	eb 26                	jmp    80489bf <phase_3+0x85>
 8048999:	b8 b9 03 00 00       	mov    $0x3b9,%eax						# case(5)
 804899e:	eb 1f                	jmp    80489bf <phase_3+0x85>
 80489a0:	b8 cb 02 00 00       	mov    $0x2cb,%eax						# case(6)
 80489a5:	eb 18                	jmp    80489bf <phase_3+0x85>
 80489a7:	b8 67 03 00 00       	mov    $0x367,%eax						# case(7)
 80489ac:	eb 11                	jmp    80489bf <phase_3+0x85>
 80489ae:	e8 82 04 00 00       	call   8048e35 <explode_bomb>			# 第一个参数大于7发生爆炸
 80489b3:	b8 00 00 00 00       	mov    $0x0,%eax
 80489b8:	eb 05                	jmp    80489bf <phase_3+0x85>
 80489ba:	b8 64 01 00 00       	mov    $0x164,%eax						# case(1)
# case语句中的赋值和第二个参数比较
 80489bf:	3b 44 24 1c          	cmp    0x1c(%esp),%eax
 80489c3:	74 05                	je     80489ca <phase_3+0x90>			# 相等跳转到销毁栈帧
 80489c5:	e8 6b 04 00 00       	call   8048e35 <explode_bomb>			# 不相等则炸弹爆炸
# 销毁栈帧
 80489ca:	83 c4 2c             	add    $0x2c,%esp
 80489cd:	c3                   	ret

080489ce <func4>:
# 保存寄存器和建立栈帧
 80489ce:	57                   	push   %edi
 80489cf:	56                   	push   %esi
 80489d0:	53                   	push   %ebx
 80489d1:	83 ec 10             	sub    $0x10,%esp
# 如果第一个参数<=0,直接返回
 80489d4:	8b 5c 24 20          	mov    0x20(%esp),%ebx					# %ebx=第一个参数，设为x
 80489d8:	8b 74 24 24          	mov    0x24(%esp),%esi					# %esi=第二个参数,输入的第二个数据,设为y
 80489dc:	85 db                	test   %ebx,%ebx						
 80489de:	7e 2c                	jle    8048a0c <func4+0x3e>				# 如果第一个参数x小于等于0，直接跳转到返回 0
# 如果第一个参数==1，返回第一个参数
 80489e0:	89 f0                	mov    %esi,%eax						# %eax=第二个数据y
 80489e2:	83 fb 01             	cmp    $0x1,%ebx						
 80489e5:	74 2a                	je     8048a11 <func4+0x43>				# 如果第一个参数x==1，直接返回第二个参数
# 第一次递归调用 
 80489e7:	89 74 24 04          	mov    %esi,0x4(%esp)					# 准备第二个参数，等于y
 80489eb:	8d 43 ff             	lea    -0x1(%ebx),%eax					
 80489ee:	89 04 24             	mov    %eax,(%esp)						# 准备第一个参数，等于x-1
 80489f1:	e8 d8 ff ff ff       	call   80489ce <func4>
# 保存结果
 80489f6:	8d 3c 30             	lea    (%eax,%esi,1),%edi				# %edi=func4(x-1,y)+y
# 第二次递归调用
 80489f9:	89 74 24 04          	mov    %esi,0x4(%esp)					# 第二个参数，等于y
 80489fd:	83 eb 02             	sub    $0x2,%ebx
 8048a00:	89 1c 24             	mov    %ebx,(%esp)						# 第一个参数，等于x-2
 8048a03:	e8 c6 ff ff ff       	call   80489ce <func4>
# 保存结果，并返回销毁栈帧
 8048a08:	01 f8                	add    %edi,%eax						# %eax=func4(x-1,y)+y+func4(x-2,y)						
 8048a0a:	eb 05                	jmp    8048a11 <func4+0x43>
 8048a0c:	b8 00 00 00 00       	mov    $0x0,%eax
 8048a11:	83 c4 10             	add    $0x10,%esp
 8048a14:	5b                   	pop    %ebx
 8048a15:	5e                   	pop    %esi
 8048a16:	5f                   	pop    %edi
 8048a17:	c3                   	ret

08048a18 <phase_4>:
# 建立栈帧
 8048a18:	83 ec 2c             	sub    $0x2c,%esp
# 准备sscanf的参数
 8048a1b:	8d 44 24 18          	lea    0x18(%esp),%eax					
 8048a1f:	89 44 24 0c          	mov    %eax,0xc(%esp)					# 第四个参数，输入的第二个数据
 8048a23:	8d 44 24 1c          	lea    0x1c(%esp),%eax
 8048a27:	89 44 24 08          	mov    %eax,0x8(%esp)					# 第三个参数，输入的第一个数据
 8048a2b:	c7 44 24 04 f1 93 04 	movl   $0x80493f1,0x4(%esp)				# 第二个参数
 8048a32:	08 
 8048a33:	8b 44 24 30          	mov    0x30(%esp),%eax
 8048a37:	89 04 24             	mov    %eax,(%esp)						# 第一个参数
 8048a3a:	e8 c1 fb ff ff       	call   8048600 <__isoc99_sscanf@plt>
# 判断输入数据是否合法
 8048a3f:	83 f8 02             	cmp    $0x2,%eax						
 8048a42:	75 0c                	jne    8048a50 <phase_4+0x38>			# 如果输入数据小于等于2，直接跳转到炸弹爆炸
# 判断输入的二个数字是否合法
 8048a44:	8b 44 24 18          	mov    0x18(%esp),%eax
 8048a48:	83 e8 02             	sub    $0x2,%eax
 8048a4b:	83 f8 02             	cmp    $0x2,%eax
 8048a4e:	76 05                	jbe    8048a55 <phase_4+0x3d>
 8048a50:	e8 e0 03 00 00       	call   8048e35 <explode_bomb>			# 输入数据不合法，第一个数据大于4，都会爆炸
# 准备func4的参数并调用该函数
 8048a55:	8b 44 24 18          	mov    0x18(%esp),%eax
 8048a59:	89 44 24 04          	mov    %eax,0x4(%esp)					# func4的第二个参数,输入的第二个数据
 8048a5d:	c7 04 24 07 00 00 00 	movl   $0x7,(%esp)						# func4的第一个参数，0x7
 8048a64:	e8 65 ff ff ff       	call   80489ce <func4>					
# 比较func返回结果和输入第一个数据大小关系
 8048a69:	3b 44 24 1c          	cmp    0x1c(%esp),%eax
 8048a6d:	74 05                	je     8048a74 <phase_4+0x5c>
 8048a6f:	e8 c1 03 00 00       	call   8048e35 <explode_bomb>			# func4的返回值和输入的第一个数据不相等，爆炸
# 销毁栈帧
 8048a74:	83 c4 2c             	add    $0x2c,%esp
 8048a77:	c3                   	ret

08048a78 <phase_5>:
# 建立栈帧
 8048a78:	83 ec 2c             	sub    $0x2c,%esp
# 准备参数并调用sscanf
 8048a7b:	8d 44 24 1c          	lea    0x1c(%esp),%eax					
 8048a7f:	89 44 24 0c          	mov    %eax,0xc(%esp)					# 准备第四个参数，输入的第二个数字,不妨设为y
 8048a83:	8d 44 24 18          	lea    0x18(%esp),%eax		
 8048a87:	89 44 24 08          	mov    %eax,0x8(%esp)					# 准备第三个参数，输入的第一个数字,不妨设为x
 8048a8b:	c7 44 24 04 f1 93 04 	movl   $0x80493f1,0x4(%esp)				# 准备第二个参数 "%d %d"
 8048a92:	08 
 8048a93:	8b 44 24 30          	mov    0x30(%esp),%eax					# 准备第一个参数，输入的字符串
 8048a97:	89 04 24             	mov    %eax,(%esp)
 8048a9a:	e8 61 fb ff ff       	call   8048600 <__isoc99_sscanf@plt>
# 判断输入是否合法 
 8048a9f:	83 f8 01             	cmp    $0x1,%eax
 8048aa2:	7f 05                	jg     8048aa9 <phase_5+0x31>
 8048aa4:	e8 8c 03 00 00       	call   8048e35 <explode_bomb>			# 如果输入的数据个数小于等于1，炸弹爆炸
# 把输入的第一个数字%16并判断输入的第一个数字是否合法 
 8048aa9:	8b 44 24 18          	mov    0x18(%esp),%eax					# %eax=输入的第一个数字
 8048aad:	83 e0 0f             	and    $0xf,%eax						# 对x取模16 
 8048ab0:	89 44 24 18          	mov    %eax,0x18(%esp)					# 把取模后的x放回源地址
 8048ab4:	83 f8 0f             	cmp    $0xf,%eax						
 8048ab7:	74 2a                	je     8048ae3 <phase_5+0x6b>			# 取模后的x如果等于0xf，直接跳到炸弹爆炸
# 循环
 8048ab9:	b9 00 00 00 00       	mov    $0x0,%ecx						# %ecx=0 ，初始化累加变量
 8048abe:	ba 00 00 00 00       	mov    $0x0,%edx						# %edx=0 ，初始化循环变量
 8048ac3:	83 c2 01             	add    $0x1,%edx						# %edx++
 8048ac6:	8b 04 85 a0 92 04 08 	mov    0x80492a0(,%eax,4),%eax			# %eax=arr[%eax]
 8048acd:	01 c1                	add    %eax,%ecx						# %ecx+=%eax
 8048acf:	83 f8 0f             	cmp    $0xf,%eax						
 8048ad2:	75 ef                	jne    8048ac3 <phase_5+0x4b>			# 如果%eax!=0xf
# %eax存放回去
 8048ad4:	89 44 24 18          	mov    %eax,0x18(%esp)					# %eax存放回去
# 比较循环次数和循环中累加的%ecx是否等于输入的第二个数字
 8048ad8:	83 fa 0f             	cmp    $0xf,%edx
 8048adb:	75 06                	jne    8048ae3 <phase_5+0x6b>			# 循环次数不等于0xf跳转到爆炸
 8048add:	3b 4c 24 1c          	cmp    0x1c(%esp),%ecx
 8048ae1:	74 05                	je     8048ae8 <phase_5+0x70>			# 循环累加和不等于第二个数字跳转到爆炸
 8048ae3:	e8 4d 03 00 00       	call   8048e35 <explode_bomb>			# x不合法，循环次数不等于0xf以及累加和不等于y
# 销毁栈帧并返回
 8048ae8:	83 c4 2c             	add    $0x2c,%esp
 8048aeb:	c3                   	ret

08048aec <phase_6>:
# 建立栈帧
 8048aec:	56                   	push   %esi
 8048aed:	53                   	push   %ebx
 8048aee:	83 ec 44             	sub    $0x44,%esp
# 准备read_six_number参数并调用该函数
 8048af1:	8d 44 24 10          	lea    0x10(%esp),%eax
 8048af5:	89 44 24 04          	mov    %eax,0x4(%esp)					# 第二个参数，当前栈帧开的数组arr的首地址
 8048af9:	8b 44 24 50          	mov    0x50(%esp),%eax	
 8048afd:	89 04 24             	mov    %eax,(%esp)						# 第一个参数，输入的字符串（当前函数的参数）
 8048b00:	e8 57 03 00 00       	call   8048e5c <read_six_numbers>
# 双层循环（验证输入序列是否为1-6的一个排列）
 8048b05:	be 00 00 00 00       	mov    $0x0,%esi						# %esi=0,循环变量初始化为0
 8048b0a:	8b 44 b4 10          	mov    0x10(%esp,%esi,4),%eax			# %eax=arr[%esi]
 8048b0e:	83 e8 01             	sub    $0x1,%eax						# %eax--
 8048b11:	83 f8 05             	cmp    $0x5,%eax						
 8048b14:	76 05                	jbe    8048b1b <phase_6+0x2f>			# 如果%eax<=5,跳过炸弹爆炸
 8048b16:	e8 1a 03 00 00       	call   8048e35 <explode_bomb>			# 否则，炸弹爆炸
 8048b1b:	83 c6 01             	add    $0x1,%esi						# %esi++
 8048b1e:	83 fe 06             	cmp    $0x6,%esi						
 8048b21:	75 07                	jne    8048b2a <phase_6+0x3e>			
# 相当于一个break语句
 8048b23:	bb 00 00 00 00       	mov    $0x0,%ebx						# 如果%esi==6,%ebx=0
 8048b28:	eb 39                	jmp    8048b63 <phase_6+0x77>			# 跳出当前循环
# 内层循环
 8048b2a:	89 f3                	mov    %esi,%ebx						# 否则%ebx=%esi
 8048b2c:	8b 44 9c 10          	mov    0x10(%esp,%ebx,4),%eax			# %eax=arr[%ebx]
 8048b30:	39 44 b4 0c          	cmp    %eax,0xc(%esp,%esi,4)			# cmp arr[%ebx]:arr[%esi-1]
 8048b34:	75 05                	jne    8048b3b <phase_6+0x4f>			# 如果不相等，跳过炸弹爆炸
 8048b36:	e8 fa 02 00 00       	call   8048e35 <explode_bomb>			# 否则，炸弹爆炸
 8048b3b:	83 c3 01             	add    $0x1,%ebx						# %ebx++
 8048b3e:	83 fb 05             	cmp    $0x5,%ebx						
 8048b41:	7e e9                	jle    8048b2c <phase_6+0x40>			# 如果%ebx<=5，继续内层循环
 8048b43:	eb c5                	jmp    8048b0a <phase_6+0x1e>			# 否则，内层循环结束，继续外层循环
# 循环(链表重排)
# %ecx>1,此处依旧是个循环(找到和当前数组元素对应的节点)
 8048b45:	8b 52 08             	mov    0x8(%edx),%edx					# node=node->next，存到%edx
 8048b48:	83 c0 01             	add    $0x1,%eax						# %eax++
 8048b4b:	39 c8                	cmp    %ecx,%eax						 
 8048b4d:	75 f6                	jne    8048b45 <phase_6+0x59>			# 如果%eax!=%ecx，继续循环
 8048b4f:	90                   	nop
 8048b50:	eb 05                	jmp    8048b57 <phase_6+0x6b>			# 否则找到对应节点，跳转到合并处存放节点
# 如果%ecx<=1,跳到此处
 8048b52:	ba 1c b1 04 08       	mov    $0x804b11c,%edx					# %edx=node1，然后存放节点
# if_else合并处存放节点
 8048b57:	89 54 b4 28          	mov    %edx,0x28(%esp,%esi,4)			# 把node1存到当前栈帧的某个地址
 8048b5b:	83 c3 01             	add    $0x1,%ebx						# %ebx++
 8048b5e:	83 fb 06             	cmp    $0x6,%ebx
 8048b61:	74 17                	je     8048b7a <phase_6+0x8e>			# 如果%ebx==6，跳出循环
# 双重循环跳到此处
 8048b63:	89 de                	mov    %ebx,%esi						# %esi=%ebx=0,%ebx为循环变量
 8048b65:	8b 4c 9c 10          	mov    0x10(%esp,%ebx,4),%ecx			# %ecx=arr[%ebx]
# 条件分支
 8048b69:	83 f9 01             	cmp    $0x1,%ecx
 8048b6c:	7e e4                	jle    8048b52 <phase_6+0x66>			# 如果%ecx<=1,跳转
 8048b6e:	b8 01 00 00 00       	mov    $0x1,%eax						# 否则，%eax=1
 8048b73:	ba 1c b1 04 08       	mov    $0x804b11c,%edx					# %edx=node1,设为node
 8048b78:	eb cb                	jmp    8048b45 <phase_6+0x59>			# 无条件跳转到%ecx>1分支
# 循环(重连链表)
# 初始化
 8048b7a:	8b 5c 24 28          	mov    0x28(%esp),%ebx					# %ebx=重排后的第一个节点
 8048b7e:	8d 44 24 2c          	lea    0x2c(%esp),%eax					# %eax=第一个节点存放地址+0x4
 8048b82:	8d 74 24 40          	lea    0x40(%esp),%esi					# %esi=最后一个节点存放地址+0x4
 8048b86:	89 d9                	mov    %ebx,%ecx						# %ecx=%ebx，%ecx和%eax为循环变量
# 循环
 8048b88:	8b 10                	mov    (%eax),%edx						# %edx=当前节点的下一个节点
 8048b8a:	89 51 08             	mov    %edx,0x8(%ecx)					# 当前节点的next=下一个节点
 8048b8d:	83 c0 04             	add    $0x4,%eax						# %eax+=0x4,更新当前节点下一个节点
# 循环条件
 8048b90:	39 f0                	cmp    %esi,%eax						
 8048b92:	74 04                	je     8048b98 <phase_6+0xac>			# 如果更新后当前节点的下一个节点没有节点
# 循环变量更新
 8048b94:	89 d1                	mov    %edx,%ecx						# 当前节点下一个节点赋给当前节点
 8048b96:	eb f0                	jmp    8048b88 <phase_6+0x9c>			# 循环	
# 最后一个节点next设置为空
 8048b98:	c7 42 08 00 00 00 00 	movl   $0x0,0x8(%edx)					# 链表的最后一个节点next设置为空指针
# 循环(检验答案)，%ebx继承重排后头节点
 8048b9f:	be 05 00 00 00       	mov    $0x5,%esi						# %esi=0x5			
 8048ba4:	8b 43 08             	mov    0x8(%ebx),%eax					# %eax=当前节点的next
 8048ba7:	8b 00                	mov    (%eax),%eax						# %eax=node->next->val	
 8048ba9:	39 03                	cmp    %eax,(%ebx)						# cmp node->next->val:node->val
 8048bab:	7e 05                	jle    8048bb2 <phase_6+0xc6>			# 当前节点值小于等于下一个节点值，跳转
 8048bad:	e8 83 02 00 00       	call   8048e35 <explode_bomb>			# 否则炸弹爆炸
 8048bb2:	8b 5b 08             	mov    0x8(%ebx),%ebx					# 跟新当前节点为其next
 8048bb5:	83 ee 01             	sub    $0x1,%esi						# %esi--
 8048bb8:	75 ea                	jne    8048ba4 <phase_6+0xb8>			# %esi!=0，继续循环
# 销毁栈帧
 8048bba:	83 c4 44             	add    $0x44,%esp
 8048bbd:	5b                   	pop    %ebx
 8048bbe:	5e                   	pop    %esi
 8048bbf:	c3                   	ret

08048bc0 <fun7>: # fun7(root,第二个参数)
# 保存寄存器并建立栈帧
 8048bc0:	53                   	push   %ebx
 8048bc1:	83 ec 18             	sub    $0x18,%esp
# 判断是否到base case
 8048bc4:	8b 54 24 20          	mov    0x20(%esp),%edx					# %edx=root
 8048bc8:	8b 4c 24 24          	mov    0x24(%esp),%ecx					# %ecx=第二个参数
 8048bcc:	85 d2                	test   %edx,%edx						
 8048bce:	74 37                	je     8048c07 <fun7+0x47>				# if(root=null) 直接返回		
# Inductive step
 8048bd0:	8b 1a                	mov    (%edx),%ebx						# %ebx=root->val
 8048bd2:	39 cb                	cmp    %ecx,%ebx						
 8048bd4:	7e 13                	jle    8048be9 <fun7+0x29>				# 当前节点值小于等于第二个参数
# 当前节点值大于第二个参数,准备参数递归调用fun7(root->left,第二个参数)
 8048bd6:	89 4c 24 04          	mov    %ecx,0x4(%esp)					# 第二个参数为该函数的第二个参数
 8048bda:	8b 42 04             	mov    0x4(%edx),%eax					# root->left
 8048bdd:	89 04 24             	mov    %eax,(%esp)						# 第一个参数为root->left
 8048be0:	e8 db ff ff ff       	call   8048bc0 <fun7>					# %eax=fun7(root->left,%ecx)
 8048be5:	01 c0                	add    %eax,%eax						# return %eax*2
 8048be7:	eb 23                	jmp    8048c0c <fun7+0x4c>				# 直接跳转到返回
# 当前节点值等于第二个参数,直接返回0
 8048be9:	b8 00 00 00 00       	mov    $0x0,%eax						# %eax=0
 8048bee:	39 cb                	cmp    %ecx,%ebx						
 8048bf0:	74 1a                	je     8048c0c <fun7+0x4c>				# 当前节点值等于第二个参数，返回0
# 当前节点值小于第二个参数,准备参数递归调用
 8048bf2:	89 4c 24 04          	mov    %ecx,0x4(%esp)					# 第二参数
 8048bf6:	8b 42 08             	mov    0x8(%edx),%eax					# root->right
 8048bf9:	89 04 24             	mov    %eax,(%esp)						# %eax=fun7(root->right,%ecx)
 8048bfc:	e8 bf ff ff ff       	call   8048bc0 <fun7>					
 8048c01:	8d 44 00 01          	lea    0x1(%eax,%eax,1),%eax			# return %eax*2+1
 8048c05:	eb 05                	jmp    8048c0c <fun7+0x4c>
# 如果为空返回0xffffffff
 8048c07:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
# 销毁栈帧
 8048c0c:	83 c4 18             	add    $0x18,%esp
 8048c0f:	5b                   	pop    %ebx
 8048c10:	c3                   	ret

08048c11 <secret_phase>:
# 建立栈帧
 8048c11:	53                   	push   %ebx
 8048c12:	83 ec 18             	sub    $0x18,%esp
# 读取字符串
 8048c15:	e8 92 02 00 00       	call   8048eac <read_line>
# 准备参数并调用strtol(const char *nptr, char **endptr, int base)
 8048c1a:	c7 44 24 08 0a 00 00 	movl   $0xa,0x8(%esp)				# 第三个参数,转为10进制
 8048c21:	00 		
 8048c22:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)				# 第二个参数，不需要
 8048c29:	00 
 8048c2a:	89 04 24             	mov    %eax,(%esp)					# 第一个参数：readline返回值，要解析的字符串
 8048c2d:	e8 fe f9 ff ff       	call   8048630 <strtol@plt>
# 判断函数返回值是否合法
 8048c32:	89 c3                	mov    %eax,%ebx	
 8048c34:	8d 40 ff             	lea    -0x1(%eax),%eax
 8048c37:	3d e8 03 00 00       	cmp    $0x3e8,%eax					
 8048c3c:	76 05                	jbe    8048c43 <secret_phase+0x32>	# %eax-1<=0x3e8时，直接跳转,0x3e9为二叉树最大节点值
 8048c3e:	e8 f2 01 00 00       	call   8048e35 <explode_bomb>		# 否则，炸弹爆炸
# 准备参数并调用fun7
 8048c43:	89 5c 24 04          	mov    %ebx,0x4(%esp)				# 第二个参数，strtol返回值 
 8048c47:	c7 04 24 68 b0 04 08 	movl   $0x804b068,(%esp)			# 第一个参数，二叉树根节点
 8048c4e:	e8 6d ff ff ff       	call   8048bc0 <fun7>
# 判断函数返回值是否合法
 8048c53:	83 f8 04             	cmp    $0x4,%eax
 8048c56:	74 05                	je     8048c5d <secret_phase+0x4c>	# %eax=4，直接跳转
 8048c58:	e8 d8 01 00 00       	call   8048e35 <explode_bomb>		# 否则，炸弹爆炸
 8048c5d:	c7 04 24 54 92 04 08 	movl   $0x8049254,(%esp)			# "Wow! You've defused the secret stage!"
 8048c64:	e8 57 f9 ff ff       	call   80485c0 <puts@plt>
 8048c69:	e8 38 03 00 00       	call   8048fa6 <phase_defused>
# 销毁栈帧
 8048c6e:	83 c4 18             	add    $0x18,%esp
 8048c71:	5b                   	pop    %ebx
 8048c72:	c3                   	ret
# 不参与任何实际逻辑，只是编译器的对齐优化手段(来自deepseek)
 8048c73:	66 90                	xchg   %ax,%ax
 8048c75:	66 90                	xchg   %ax,%ax
 8048c77:	66 90                	xchg   %ax,%ax
 8048c79:	66 90                	xchg   %ax,%ax
 8048c7b:	66 90                	xchg   %ax,%ax
 8048c7d:	66 90                	xchg   %ax,%ax
 8048c7f:	90                   	nop

08048c80 <sig_handler>:
 8048c80:	83 ec 1c             	sub    $0x1c,%esp
 8048c83:	c7 04 24 e0 92 04 08 	movl   $0x80492e0,(%esp)
 8048c8a:	e8 31 f9 ff ff       	call   80485c0 <puts@plt>
 8048c8f:	c7 04 24 03 00 00 00 	movl   $0x3,(%esp)
 8048c96:	e8 f5 f8 ff ff       	call   8048590 <sleep@plt>
 8048c9b:	c7 44 24 04 a4 93 04 	movl   $0x80493a4,0x4(%esp)
 8048ca2:	08 
 8048ca3:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048caa:	e8 71 f9 ff ff       	call   8048620 <__printf_chk@plt>
 8048caf:	a1 a0 b3 04 08       	mov    0x804b3a0,%eax
 8048cb4:	89 04 24             	mov    %eax,(%esp)
 8048cb7:	e8 a4 f8 ff ff       	call   8048560 <fflush@plt>
 8048cbc:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048cc3:	e8 c8 f8 ff ff       	call   8048590 <sleep@plt>
 8048cc8:	c7 04 24 ac 93 04 08 	movl   $0x80493ac,(%esp)
 8048ccf:	e8 ec f8 ff ff       	call   80485c0 <puts@plt>
 8048cd4:	c7 04 24 10 00 00 00 	movl   $0x10,(%esp)
 8048cdb:	e8 00 f9 ff ff       	call   80485e0 <exit@plt>

08048ce0 <invalid_phase>:
 8048ce0:	83 ec 1c             	sub    $0x1c,%esp
 8048ce3:	8b 44 24 20          	mov    0x20(%esp),%eax
 8048ce7:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048ceb:	c7 44 24 04 b4 93 04 	movl   $0x80493b4,0x4(%esp)
 8048cf2:	08 
 8048cf3:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048cfa:	e8 21 f9 ff ff       	call   8048620 <__printf_chk@plt>
 8048cff:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8048d06:	e8 d5 f8 ff ff       	call   80485e0 <exit@plt>

08048d0b <string_length>:
 8048d0b:	8b 54 24 04          	mov    0x4(%esp),%edx
 8048d0f:	80 3a 00             	cmpb   $0x0,(%edx)
 8048d12:	74 10                	je     8048d24 <string_length+0x19>
 8048d14:	b8 00 00 00 00       	mov    $0x0,%eax
 8048d19:	83 c0 01             	add    $0x1,%eax
 8048d1c:	80 3c 02 00          	cmpb   $0x0,(%edx,%eax,1)
 8048d20:	75 f7                	jne    8048d19 <string_length+0xe>
 8048d22:	f3 c3                	repz ret
 8048d24:	b8 00 00 00 00       	mov    $0x0,%eax
 8048d29:	c3                   	ret

08048d2a <strings_not_equal>:
 8048d2a:	57                   	push   %edi
 8048d2b:	56                   	push   %esi
 8048d2c:	53                   	push   %ebx
 8048d2d:	83 ec 04             	sub    $0x4,%esp
 8048d30:	8b 5c 24 14          	mov    0x14(%esp),%ebx
 8048d34:	8b 74 24 18          	mov    0x18(%esp),%esi
 8048d38:	89 1c 24             	mov    %ebx,(%esp)
 8048d3b:	e8 cb ff ff ff       	call   8048d0b <string_length>
 8048d40:	89 c7                	mov    %eax,%edi
 8048d42:	89 34 24             	mov    %esi,(%esp)
 8048d45:	e8 c1 ff ff ff       	call   8048d0b <string_length>
 8048d4a:	ba 01 00 00 00       	mov    $0x1,%edx
 8048d4f:	39 c7                	cmp    %eax,%edi
 8048d51:	75 3a                	jne    8048d8d <strings_not_equal+0x63>
 8048d53:	0f b6 03             	movzbl (%ebx),%eax
 8048d56:	84 c0                	test   %al,%al
 8048d58:	74 20                	je     8048d7a <strings_not_equal+0x50>
 8048d5a:	3a 06                	cmp    (%esi),%al
 8048d5c:	74 08                	je     8048d66 <strings_not_equal+0x3c>
 8048d5e:	66 90                	xchg   %ax,%ax
 8048d60:	eb 1f                	jmp    8048d81 <strings_not_equal+0x57>
 8048d62:	3a 06                	cmp    (%esi),%al
 8048d64:	75 22                	jne    8048d88 <strings_not_equal+0x5e>
 8048d66:	83 c3 01             	add    $0x1,%ebx
 8048d69:	83 c6 01             	add    $0x1,%esi
 8048d6c:	0f b6 03             	movzbl (%ebx),%eax
 8048d6f:	84 c0                	test   %al,%al
 8048d71:	75 ef                	jne    8048d62 <strings_not_equal+0x38>
 8048d73:	ba 00 00 00 00       	mov    $0x0,%edx
 8048d78:	eb 13                	jmp    8048d8d <strings_not_equal+0x63>
 8048d7a:	ba 00 00 00 00       	mov    $0x0,%edx
 8048d7f:	eb 0c                	jmp    8048d8d <strings_not_equal+0x63>
 8048d81:	ba 01 00 00 00       	mov    $0x1,%edx
 8048d86:	eb 05                	jmp    8048d8d <strings_not_equal+0x63>
 8048d88:	ba 01 00 00 00       	mov    $0x1,%edx
 8048d8d:	89 d0                	mov    %edx,%eax
 8048d8f:	83 c4 04             	add    $0x4,%esp
 8048d92:	5b                   	pop    %ebx
 8048d93:	5e                   	pop    %esi
 8048d94:	5f                   	pop    %edi
 8048d95:	c3                   	ret

08048d96 <initialize_bomb>:
 8048d96:	83 ec 1c             	sub    $0x1c,%esp
 8048d99:	c7 44 24 04 80 8c 04 	movl   $0x8048c80,0x4(%esp)
 8048da0:	08 
 8048da1:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
 8048da8:	e8 d3 f7 ff ff       	call   8048580 <signal@plt>
 8048dad:	83 c4 1c             	add    $0x1c,%esp
 8048db0:	c3                   	ret

08048db1 <initialize_bomb_solve>:
 8048db1:	f3 c3                	repz ret

08048db3 <blank_line>:
 8048db3:	56                   	push   %esi
 8048db4:	53                   	push   %ebx
 8048db5:	83 ec 04             	sub    $0x4,%esp
 8048db8:	8b 5c 24 10          	mov    0x10(%esp),%ebx
 8048dbc:	eb 16                	jmp    8048dd4 <blank_line+0x21>
 8048dbe:	e8 7d f8 ff ff       	call   8048640 <__ctype_b_loc@plt>
 8048dc3:	83 c3 01             	add    $0x1,%ebx
 8048dc6:	89 f2                	mov    %esi,%edx
 8048dc8:	0f be f2             	movsbl %dl,%esi
 8048dcb:	8b 00                	mov    (%eax),%eax
 8048dcd:	f6 44 70 01 20       	testb  $0x20,0x1(%eax,%esi,2)
 8048dd2:	74 10                	je     8048de4 <blank_line+0x31>
 8048dd4:	0f b6 33             	movzbl (%ebx),%esi
 8048dd7:	89 f0                	mov    %esi,%eax
 8048dd9:	84 c0                	test   %al,%al
 8048ddb:	75 e1                	jne    8048dbe <blank_line+0xb>
 8048ddd:	b8 01 00 00 00       	mov    $0x1,%eax
 8048de2:	eb 05                	jmp    8048de9 <blank_line+0x36>
 8048de4:	b8 00 00 00 00       	mov    $0x0,%eax
 8048de9:	83 c4 04             	add    $0x4,%esp
 8048dec:	5b                   	pop    %ebx
 8048ded:	5e                   	pop    %esi
 8048dee:	c3                   	ret

08048def <skip>:
 8048def:	53                   	push   %ebx
 8048df0:	83 ec 18             	sub    $0x18,%esp
 8048df3:	a1 ac b3 04 08       	mov    0x804b3ac,%eax
 8048df8:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048dfc:	c7 44 24 04 50 00 00 	movl   $0x50,0x4(%esp)
 8048e03:	00 
 8048e04:	a1 a8 b3 04 08       	mov    0x804b3a8,%eax
 8048e09:	8d 04 80             	lea    (%eax,%eax,4),%eax
 8048e0c:	c1 e0 04             	shl    $0x4,%eax
 8048e0f:	05 c0 b3 04 08       	add    $0x804b3c0,%eax
 8048e14:	89 04 24             	mov    %eax,(%esp)
 8048e17:	e8 54 f7 ff ff       	call   8048570 <fgets@plt>
 8048e1c:	89 c3                	mov    %eax,%ebx
 8048e1e:	85 c0                	test   %eax,%eax
 8048e20:	74 0c                	je     8048e2e <skip+0x3f>
 8048e22:	89 04 24             	mov    %eax,(%esp)
 8048e25:	e8 89 ff ff ff       	call   8048db3 <blank_line>
 8048e2a:	85 c0                	test   %eax,%eax
 8048e2c:	75 c5                	jne    8048df3 <skip+0x4>
 8048e2e:	89 d8                	mov    %ebx,%eax
 8048e30:	83 c4 18             	add    $0x18,%esp
 8048e33:	5b                   	pop    %ebx
 8048e34:	c3                   	ret

08048e35 <explode_bomb>:
 8048e35:	83 ec 1c             	sub    $0x1c,%esp
 8048e38:	c7 04 24 c5 93 04 08 	movl   $0x80493c5,(%esp)
 8048e3f:	e8 7c f7 ff ff       	call   80485c0 <puts@plt>
 8048e44:	c7 04 24 ce 93 04 08 	movl   $0x80493ce,(%esp)
 8048e4b:	e8 70 f7 ff ff       	call   80485c0 <puts@plt>
 8048e50:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8048e57:	e8 84 f7 ff ff       	call   80485e0 <exit@plt>

08048e5c <read_six_numbers>:
 8048e5c:	83 ec 2c             	sub    $0x2c,%esp
 8048e5f:	8b 44 24 34          	mov    0x34(%esp),%eax
 8048e63:	8d 50 14             	lea    0x14(%eax),%edx
 8048e66:	89 54 24 1c          	mov    %edx,0x1c(%esp)
 8048e6a:	8d 50 10             	lea    0x10(%eax),%edx
 8048e6d:	89 54 24 18          	mov    %edx,0x18(%esp)
 8048e71:	8d 50 0c             	lea    0xc(%eax),%edx
 8048e74:	89 54 24 14          	mov    %edx,0x14(%esp)
 8048e78:	8d 50 08             	lea    0x8(%eax),%edx
 8048e7b:	89 54 24 10          	mov    %edx,0x10(%esp)
 8048e7f:	8d 50 04             	lea    0x4(%eax),%edx
 8048e82:	89 54 24 0c          	mov    %edx,0xc(%esp)
 8048e86:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048e8a:	c7 44 24 04 e5 93 04 	movl   $0x80493e5,0x4(%esp)
 8048e91:	08 
 8048e92:	8b 44 24 30          	mov    0x30(%esp),%eax
 8048e96:	89 04 24             	mov    %eax,(%esp)
 8048e99:	e8 62 f7 ff ff       	call   8048600 <__isoc99_sscanf@plt>
 8048e9e:	83 f8 05             	cmp    $0x5,%eax
 8048ea1:	7f 05                	jg     8048ea8 <read_six_numbers+0x4c>
 8048ea3:	e8 8d ff ff ff       	call   8048e35 <explode_bomb>
 8048ea8:	83 c4 2c             	add    $0x2c,%esp
 8048eab:	c3                   	ret

08048eac <read_line>:
 8048eac:	57                   	push   %edi
 8048ead:	56                   	push   %esi
 8048eae:	53                   	push   %ebx
 8048eaf:	83 ec 10             	sub    $0x10,%esp
 8048eb2:	e8 38 ff ff ff       	call   8048def <skip>
 8048eb7:	85 c0                	test   %eax,%eax
 8048eb9:	75 6c                	jne    8048f27 <read_line+0x7b>
 8048ebb:	a1 80 b3 04 08       	mov    0x804b380,%eax
 8048ec0:	39 05 ac b3 04 08    	cmp    %eax,0x804b3ac
 8048ec6:	75 18                	jne    8048ee0 <read_line+0x34>
 8048ec8:	c7 04 24 f7 93 04 08 	movl   $0x80493f7,(%esp)
 8048ecf:	e8 ec f6 ff ff       	call   80485c0 <puts@plt>
 8048ed4:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8048edb:	e8 00 f7 ff ff       	call   80485e0 <exit@plt>
 8048ee0:	c7 04 24 15 94 04 08 	movl   $0x8049415,(%esp)
 8048ee7:	e8 c4 f6 ff ff       	call   80485b0 <getenv@plt>
 8048eec:	85 c0                	test   %eax,%eax
 8048eee:	74 0c                	je     8048efc <read_line+0x50>
 8048ef0:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048ef7:	e8 e4 f6 ff ff       	call   80485e0 <exit@plt>
 8048efc:	a1 80 b3 04 08       	mov    0x804b380,%eax
 8048f01:	a3 ac b3 04 08       	mov    %eax,0x804b3ac
 8048f06:	e8 e4 fe ff ff       	call   8048def <skip>
 8048f0b:	85 c0                	test   %eax,%eax
 8048f0d:	75 18                	jne    8048f27 <read_line+0x7b>
 8048f0f:	c7 04 24 f7 93 04 08 	movl   $0x80493f7,(%esp)
 8048f16:	e8 a5 f6 ff ff       	call   80485c0 <puts@plt>
 8048f1b:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048f22:	e8 b9 f6 ff ff       	call   80485e0 <exit@plt>
 8048f27:	8b 15 a8 b3 04 08    	mov    0x804b3a8,%edx
 8048f2d:	8d 1c 92             	lea    (%edx,%edx,4),%ebx
 8048f30:	c1 e3 04             	shl    $0x4,%ebx
 8048f33:	81 c3 c0 b3 04 08    	add    $0x804b3c0,%ebx
 8048f39:	89 df                	mov    %ebx,%edi
 8048f3b:	b8 00 00 00 00       	mov    $0x0,%eax
 8048f40:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 8048f45:	f2 ae                	repnz scas %es:(%edi),%al
 8048f47:	f7 d1                	not    %ecx
 8048f49:	83 e9 01             	sub    $0x1,%ecx
 8048f4c:	83 f9 4e             	cmp    $0x4e,%ecx
 8048f4f:	7e 35                	jle    8048f86 <read_line+0xda>
 8048f51:	c7 04 24 20 94 04 08 	movl   $0x8049420,(%esp)
 8048f58:	e8 63 f6 ff ff       	call   80485c0 <puts@plt>
 8048f5d:	a1 a8 b3 04 08       	mov    0x804b3a8,%eax
 8048f62:	8d 50 01             	lea    0x1(%eax),%edx
 8048f65:	89 15 a8 b3 04 08    	mov    %edx,0x804b3a8
 8048f6b:	6b c0 50             	imul   $0x50,%eax,%eax
 8048f6e:	05 c0 b3 04 08       	add    $0x804b3c0,%eax
 8048f73:	be 3b 94 04 08       	mov    $0x804943b,%esi
 8048f78:	b9 04 00 00 00       	mov    $0x4,%ecx
 8048f7d:	89 c7                	mov    %eax,%edi
 8048f7f:	f3 a5                	rep movsl %ds:(%esi),%es:(%edi)
 8048f81:	e8 af fe ff ff       	call   8048e35 <explode_bomb>
 8048f86:	8d 04 92             	lea    (%edx,%edx,4),%eax
 8048f89:	c1 e0 04             	shl    $0x4,%eax
 8048f8c:	c6 84 01 bf b3 04 08 	movb   $0x0,0x804b3bf(%ecx,%eax,1)
 8048f93:	00 
 8048f94:	83 c2 01             	add    $0x1,%edx
 8048f97:	89 15 a8 b3 04 08    	mov    %edx,0x804b3a8
 8048f9d:	89 d8                	mov    %ebx,%eax
 8048f9f:	83 c4 10             	add    $0x10,%esp
 8048fa2:	5b                   	pop    %ebx
 8048fa3:	5e                   	pop    %esi
 8048fa4:	5f                   	pop    %edi
 8048fa5:	c3                   	ret

08048fa6 <phase_defused>:
# 建立栈帧，并建立哨兵，防止局部变量越界
 8048fa6:	81 ec 8c 00 00 00    	sub    $0x8c,%esp
 8048fac:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax					# %eax=哨兵
 8048fb2:	89 44 24 7c          	mov    %eax,0x7c(%esp)					# 把哨兵存到的栈帧中靠近栈底的位置
 8048fb6:	31 c0                	xor    %eax,%eax						# 把%eax清零
# 判断我们通过的phase个数
 8048fb8:	83 3d a8 b3 04 08 06 	cmpl   $0x6,0x804b3a8					# 该地址存储的是num_input_strings
 8048fbf:	75 72                	jne    8049033 <phase_defused+0x8d>		# 如果我们没有通过六个关卡,直接跳转返回
# 通过六个phase
# 准备参数并调用sscanf
 8048fc1:	8d 44 24 2c          	lea    0x2c(%esp),%eax									
 8048fc5:	89 44 24 10          	mov    %eax,0x10(%esp)					# 第五个参数	
 8048fc9:	8d 44 24 28          	lea    0x28(%esp),%eax
 8048fcd:	89 44 24 0c          	mov    %eax,0xc(%esp)					# 第四个参数
 8048fd1:	8d 44 24 24          	lea    0x24(%esp),%eax
 8048fd5:	89 44 24 08          	mov    %eax,0x8(%esp)					# 第三个参数
 8048fd9:	c7 44 24 04 4b 94 04 	movl   $0x804944b,0x4(%esp)				# 第二个参数"%d %d %s"
 8048fe0:	08 
 8048fe1:	c7 04 24 b0 b4 04 08 	movl   $0x804b4b0,(%esp)				# 第一个参数，经过gdb调试发现时在phase_4
 8048fe8:	e8 13 f6 ff ff       	call   8048600 <__isoc99_sscanf@plt>
# 检查输入值
 8048fed:	83 f8 03             	cmp    $0x3,%eax						
 8048ff0:	75 35                	jne    8049027 <phase_defused+0x81>		# 如果输入数据不等于3，不会调用隐藏关卡
# 准备参数并调用strings_not_equal
 8048ff2:	c7 44 24 04 54 94 04 	movl   $0x8049454,0x4(%esp)				# 第二个参数：“DrEvil”	
 8048ff9:	08 
 8048ffa:	8d 44 24 2c          	lea    0x2c(%esp),%eax					
 8048ffe:	89 04 24             	mov    %eax,(%esp)						# 第一个参数：输入的字符串
 8049001:	e8 24 fd ff ff       	call   8048d2a <strings_not_equal>
# 判断返回值是否合法
 8049006:	85 c0                	test   %eax,%eax
 8049008:	75 1d                	jne    8049027 <phase_defused+0x81>		# 如果返回值不为0，不会调用隐藏关卡
# 打印字符串并调用隐藏关卡
 804900a:	c7 04 24 18 93 04 08 	movl   $0x8049318,(%esp)				# "Curses, you've found the secret phase!"
 8049011:	e8 aa f5 ff ff       	call   80485c0 <puts@plt>				
 8049016:	c7 04 24 40 93 04 08 	movl   $0x8049340,(%esp)				# "But finding it and solving it are quite different..."
 804901d:	e8 9e f5 ff ff       	call   80485c0 <puts@plt>				
 8049022:	e8 ea fb ff ff       	call   8048c11 <secret_phase>
# 未进入隐藏关卡但是已通过6个phase
 8049027:	c7 04 24 78 93 04 08 	movl   $0x8049378,(%esp)				# "Congratulations! You've defused the bomb!"
 804902e:	e8 8d f5 ff ff       	call   80485c0 <puts@plt>				# 打印字符串
# 检查哨兵并销毁栈帧
 8049033:	8b 44 24 7c          	mov    0x7c(%esp),%eax					# 取出哨兵
 8049037:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax					
 804903e:	74 05                	je     8049045 <phase_defused+0x9f>		# 如果哨兵值没有改变，直接跳转
 8049040:	e8 5b f5 ff ff       	call   80485a0 <__stack_chk_fail@plt>	# 否则报错
 8049045:	81 c4 8c 00 00 00    	add    $0x8c,%esp
 804904b:	c3                   	ret
 804904c:	66 90                	xchg   %ax,%ax
 804904e:	66 90                	xchg   %ax,%ax

08049050 <__libc_csu_init>:
 8049050:	55                   	push   %ebp
 8049051:	57                   	push   %edi
 8049052:	31 ff                	xor    %edi,%edi
 8049054:	56                   	push   %esi
 8049055:	53                   	push   %ebx
 8049056:	e8 25 f6 ff ff       	call   8048680 <__x86.get_pc_thunk.bx>
 804905b:	81 c3 a5 1f 00 00    	add    $0x1fa5,%ebx
 8049061:	83 ec 1c             	sub    $0x1c,%esp
 8049064:	8b 6c 24 30          	mov    0x30(%esp),%ebp
 8049068:	8d b3 0c ff ff ff    	lea    -0xf4(%ebx),%esi
 804906e:	e8 b5 f4 ff ff       	call   8048528 <_init>
 8049073:	8d 83 08 ff ff ff    	lea    -0xf8(%ebx),%eax
 8049079:	29 c6                	sub    %eax,%esi
 804907b:	c1 fe 02             	sar    $0x2,%esi
 804907e:	85 f6                	test   %esi,%esi
 8049080:	74 27                	je     80490a9 <__libc_csu_init+0x59>
 8049082:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8049088:	8b 44 24 38          	mov    0x38(%esp),%eax
 804908c:	89 2c 24             	mov    %ebp,(%esp)
 804908f:	89 44 24 08          	mov    %eax,0x8(%esp)
 8049093:	8b 44 24 34          	mov    0x34(%esp),%eax
 8049097:	89 44 24 04          	mov    %eax,0x4(%esp)
 804909b:	ff 94 bb 08 ff ff ff 	call   *-0xf8(%ebx,%edi,4)
 80490a2:	83 c7 01             	add    $0x1,%edi
 80490a5:	39 f7                	cmp    %esi,%edi
 80490a7:	75 df                	jne    8049088 <__libc_csu_init+0x38>
 80490a9:	83 c4 1c             	add    $0x1c,%esp
 80490ac:	5b                   	pop    %ebx
 80490ad:	5e                   	pop    %esi
 80490ae:	5f                   	pop    %edi
 80490af:	5d                   	pop    %ebp
 80490b0:	c3                   	ret
 80490b1:	eb 0d                	jmp    80490c0 <__libc_csu_fini>
 80490b3:	90                   	nop
 80490b4:	90                   	nop
 80490b5:	90                   	nop
 80490b6:	90                   	nop
 80490b7:	90                   	nop
 80490b8:	90                   	nop
 80490b9:	90                   	nop
 80490ba:	90                   	nop
 80490bb:	90                   	nop
 80490bc:	90                   	nop
 80490bd:	90                   	nop
 80490be:	90                   	nop
 80490bf:	90                   	nop

080490c0 <__libc_csu_fini>:
 80490c0:	f3 c3                	repz ret

Disassembly of section .fini:

080490c4 <_fini>:
 80490c4:	53                   	push   %ebx
 80490c5:	83 ec 08             	sub    $0x8,%esp
 80490c8:	e8 b3 f5 ff ff       	call   8048680 <__x86.get_pc_thunk.bx>
 80490cd:	81 c3 33 1f 00 00    	add    $0x1f33,%ebx
 80490d3:	83 c4 08             	add    $0x8,%esp
 80490d6:	5b                   	pop    %ebx
 80490d7:	c3                   	ret