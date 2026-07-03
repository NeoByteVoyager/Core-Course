
080491b6 <compute_basic>:
 80491b6:	55                   	push   %ebp
 80491b7:	89 e5                	mov    %esp,%ebp
 80491b9:	83 ec 10             	sub    $0x10,%esp
# 初始化变量
 80491bc:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%ebp)
 80491c3:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%ebp)
# 跳到循环判断
 80491ca:	eb 2c                	jmp    80491f8 <compute_basic+0x42>
# 循环主体
 80491cc:	8b 45 fc             	mov    -0x4(%ebp),%eax
 80491cf:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 80491d6:	8b 45 08             	mov    0x8(%ebp),%eax
 80491d9:	01 d0                	add    %edx,%eax
 80491db:	8b 10                	mov    (%eax),%edx
 80491dd:	8b 45 fc             	mov    -0x4(%ebp),%eax
 80491e0:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 80491e7:	8b 45 0c             	mov    0xc(%ebp),%eax
 80491ea:	01 c8                	add    %ecx,%eax
 80491ec:	8b 00                	mov    (%eax),%eax
 80491ee:	0f af c2             	imul   %edx,%eax
 80491f1:	01 45 f8             	add    %eax,-0x8(%ebp)
 80491f4:	83 45 fc 01          	addl   $0x1,-0x4(%ebp)
# 循环条件判断
 80491f8:	8b 45 fc             	mov    -0x4(%ebp),%eax
 80491fb:	3b 45 10             	cmp    0x10(%ebp),%eax
 80491fe:	7c cc                	jl     80491cc <compute_basic+0x16>
 8049200:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049203:	c9                   	leave
 8049204:	c3                   	ret

08049205 <compute_unroll8>:
 8049205:	55                   	push   %ebp
 8049206:	89 e5                	mov    %esp,%ebp
 8049208:	83 ec 10             	sub    $0x10,%esp
# 初始化变量
 804920b:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 8049212:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%ebp)
 8049219:	8b 45 10             	mov    0x10(%ebp),%eax
 804921c:	83 e8 07             	sub    $0x7,%eax
 804921f:	89 45 fc             	mov    %eax,-0x4(%ebp)
 8049222:	e9 6e 01 00 00       	jmp    8049395 <compute_unroll8+0x190>
# 1
 8049227:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804922a:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 8049231:	8b 45 08             	mov    0x8(%ebp),%eax
 8049234:	01 d0                	add    %edx,%eax
 8049236:	8b 10                	mov    (%eax),%edx
 8049238:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804923b:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 8049242:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049245:	01 c8                	add    %ecx,%eax
 8049247:	8b 00                	mov    (%eax),%eax
 8049249:	0f af c2             	imul   %edx,%eax
 804924c:	01 45 f4             	add    %eax,-0xc(%ebp)
# 2
 804924f:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049252:	83 c0 01             	add    $0x1,%eax
 8049255:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 804925c:	8b 45 08             	mov    0x8(%ebp),%eax
 804925f:	01 d0                	add    %edx,%eax
 8049261:	8b 10                	mov    (%eax),%edx
 8049263:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049266:	83 c0 01             	add    $0x1,%eax
 8049269:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 8049270:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049273:	01 c8                	add    %ecx,%eax
 8049275:	8b 00                	mov    (%eax),%eax
 8049277:	0f af c2             	imul   %edx,%eax
 804927a:	01 45 f4             	add    %eax,-0xc(%ebp)
# 3
 804927d:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049280:	83 c0 02             	add    $0x2,%eax
 8049283:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 804928a:	8b 45 08             	mov    0x8(%ebp),%eax
 804928d:	01 d0                	add    %edx,%eax
 804928f:	8b 10                	mov    (%eax),%edx
 8049291:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049294:	83 c0 02             	add    $0x2,%eax
 8049297:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 804929e:	8b 45 0c             	mov    0xc(%ebp),%eax
 80492a1:	01 c8                	add    %ecx,%eax
 80492a3:	8b 00                	mov    (%eax),%eax
 80492a5:	0f af c2             	imul   %edx,%eax
 80492a8:	01 45 f4             	add    %eax,-0xc(%ebp)
# 4
 80492ab:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80492ae:	83 c0 03             	add    $0x3,%eax
 80492b1:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 80492b8:	8b 45 08             	mov    0x8(%ebp),%eax
 80492bb:	01 d0                	add    %edx,%eax
 80492bd:	8b 10                	mov    (%eax),%edx
 80492bf:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80492c2:	83 c0 03             	add    $0x3,%eax
 80492c5:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 80492cc:	8b 45 0c             	mov    0xc(%ebp),%eax
 80492cf:	01 c8                	add    %ecx,%eax
 80492d1:	8b 00                	mov    (%eax),%eax
 80492d3:	0f af c2             	imul   %edx,%eax
 80492d6:	01 45 f4             	add    %eax,-0xc(%ebp)
# 5
 80492d9:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80492dc:	83 c0 04             	add    $0x4,%eax
 80492df:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 80492e6:	8b 45 08             	mov    0x8(%ebp),%eax
 80492e9:	01 d0                	add    %edx,%eax
 80492eb:	8b 10                	mov    (%eax),%edx
 80492ed:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80492f0:	83 c0 04             	add    $0x4,%eax
 80492f3:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 80492fa:	8b 45 0c             	mov    0xc(%ebp),%eax
 80492fd:	01 c8                	add    %ecx,%eax
 80492ff:	8b 00                	mov    (%eax),%eax
 8049301:	0f af c2             	imul   %edx,%eax
 8049304:	01 45 f4             	add    %eax,-0xc(%ebp)
# 6
 8049307:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804930a:	83 c0 05             	add    $0x5,%eax
 804930d:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 8049314:	8b 45 08             	mov    0x8(%ebp),%eax
 8049317:	01 d0                	add    %edx,%eax
 8049319:	8b 10                	mov    (%eax),%edx
 804931b:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804931e:	83 c0 05             	add    $0x5,%eax
 8049321:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 8049328:	8b 45 0c             	mov    0xc(%ebp),%eax
 804932b:	01 c8                	add    %ecx,%eax
 804932d:	8b 00                	mov    (%eax),%eax
 804932f:	0f af c2             	imul   %edx,%eax
 8049332:	01 45 f4             	add    %eax,-0xc(%ebp)
# 7
 8049335:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049338:	83 c0 06             	add    $0x6,%eax
 804933b:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 8049342:	8b 45 08             	mov    0x8(%ebp),%eax
 8049345:	01 d0                	add    %edx,%eax
 8049347:	8b 10                	mov    (%eax),%edx
 8049349:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804934c:	83 c0 06             	add    $0x6,%eax
 804934f:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 8049356:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049359:	01 c8                	add    %ecx,%eax
 804935b:	8b 00                	mov    (%eax),%eax
 804935d:	0f af c2             	imul   %edx,%eax
 8049360:	01 45 f4             	add    %eax,-0xc(%ebp)
# 8
 8049363:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049366:	83 c0 07             	add    $0x7,%eax
 8049369:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 8049370:	8b 45 08             	mov    0x8(%ebp),%eax
 8049373:	01 d0                	add    %edx,%eax
 8049375:	8b 10                	mov    (%eax),%edx
 8049377:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804937a:	83 c0 07             	add    $0x7,%eax
 804937d:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 8049384:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049387:	01 c8                	add    %ecx,%eax
 8049389:	8b 00                	mov    (%eax),%eax
 804938b:	0f af c2             	imul   %edx,%eax
 804938e:	01 45 f4             	add    %eax,-0xc(%ebp)
 8049391:	83 45 f8 08          	addl   $0x8,-0x8(%ebp)
# 第一个循环条件判断
 8049395:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049398:	3b 45 fc             	cmp    -0x4(%ebp),%eax
 804939b:	0f 8c 86 fe ff ff    	jl     8049227 <compute_unroll8+0x22>
# 跳到下一个循环判断
 80493a1:	eb 2c                	jmp    80493cf <compute_unroll8+0x1ca>
# 第二个循环主体
 80493a3:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80493a6:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 80493ad:	8b 45 08             	mov    0x8(%ebp),%eax
 80493b0:	01 d0                	add    %edx,%eax
 80493b2:	8b 10                	mov    (%eax),%edx
 80493b4:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80493b7:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 80493be:	8b 45 0c             	mov    0xc(%ebp),%eax
 80493c1:	01 c8                	add    %ecx,%eax
 80493c3:	8b 00                	mov    (%eax),%eax
 80493c5:	0f af c2             	imul   %edx,%eax
 80493c8:	01 45 f4             	add    %eax,-0xc(%ebp)
 80493cb:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
# 第二个循环判断
 80493cf:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80493d2:	3b 45 10             	cmp    0x10(%ebp),%eax
 80493d5:	7c cc                	jl     80493a3 <compute_unroll8+0x19e>
 80493d7:	8b 45 f4             	mov    -0xc(%ebp),%eax
 80493da:	c9                   	leave
 80493db:	c3                   	ret

080493dc <compute_duff>:
 80493dc:	55                   	push   %ebp
 80493dd:	89 e5                	mov    %esp,%ebp
 80493df:	83 ec 10             	sub    $0x10,%esp
# 变量的初始化:sum,i,n
 80493e2:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 80493e9:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%ebp)
 80493f0:	8b 45 10             	mov    0x10(%ebp),%eax
 80493f3:	83 c0 07             	add    $0x7,%eax
 80493f6:	8d 50 07             	lea    0x7(%eax),%edx
 80493f9:	85 c0                	test   %eax,%eax
 80493fb:	0f 48 c2             	cmovs  %edx,%eax
 80493fe:	c1 f8 03             	sar    $0x3,%eax
 8049401:	89 45 fc             	mov    %eax,-0x4(%ebp)
# 计算:size%8
 8049404:	8b 55 10             	mov    0x10(%ebp),%edx
 8049407:	89 d0                	mov    %edx,%eax
 8049409:	c1 f8 1f             	sar    $0x1f,%eax
 804940c:	c1 e8 1d             	shr    $0x1d,%eax
 804940f:	01 c2                	add    %eax,%edx
 8049411:	83 e2 07             	and    $0x7,%edx
 8049414:	29 c2                	sub    %eax,%edx
 8049416:	89 d0                	mov    %edx,%eax
# 如果超过8,不进入分支
 8049418:	83 f8 07             	cmp    $0x7,%eax
 804941b:	0f 87 78 01 00 00    	ja     8049599 <compute_duff+0x1bd>
# 根据跳转表跳转
 8049421:	8b 04 85 08 a0 04 08 	mov    0x804a008(,%eax,4),%eax
 8049428:	ff e0                	jmp    *%eax
 804942a:	90                   	nop
# case(0)
 804942b:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804942e:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 8049435:	8b 45 08             	mov    0x8(%ebp),%eax
 8049438:	01 d0                	add    %edx,%eax
 804943a:	8b 10                	mov    (%eax),%edx
 804943c:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804943f:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 8049446:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049449:	01 c8                	add    %ecx,%eax
 804944b:	8b 00                	mov    (%eax),%eax
 804944d:	0f af c2             	imul   %edx,%eax
 8049450:	01 45 f4             	add    %eax,-0xc(%ebp)
 8049453:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
# case(7)
 8049457:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804945a:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 8049461:	8b 45 08             	mov    0x8(%ebp),%eax
 8049464:	01 d0                	add    %edx,%eax
 8049466:	8b 10                	mov    (%eax),%edx
 8049468:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804946b:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 8049472:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049475:	01 c8                	add    %ecx,%eax
 8049477:	8b 00                	mov    (%eax),%eax
 8049479:	0f af c2             	imul   %edx,%eax
 804947c:	01 45 f4             	add    %eax,-0xc(%ebp)
 804947f:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
# case(6)
 8049483:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049486:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 804948d:	8b 45 08             	mov    0x8(%ebp),%eax
 8049490:	01 d0                	add    %edx,%eax
 8049492:	8b 10                	mov    (%eax),%edx
 8049494:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049497:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 804949e:	8b 45 0c             	mov    0xc(%ebp),%eax
 80494a1:	01 c8                	add    %ecx,%eax
 80494a3:	8b 00                	mov    (%eax),%eax
 80494a5:	0f af c2             	imul   %edx,%eax
 80494a8:	01 45 f4             	add    %eax,-0xc(%ebp)
 80494ab:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
# case(5)
 80494af:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80494b2:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 80494b9:	8b 45 08             	mov    0x8(%ebp),%eax
 80494bc:	01 d0                	add    %edx,%eax
 80494be:	8b 10                	mov    (%eax),%edx
 80494c0:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80494c3:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 80494ca:	8b 45 0c             	mov    0xc(%ebp),%eax
 80494cd:	01 c8                	add    %ecx,%eax
 80494cf:	8b 00                	mov    (%eax),%eax
 80494d1:	0f af c2             	imul   %edx,%eax
 80494d4:	01 45 f4             	add    %eax,-0xc(%ebp)
 80494d7:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
# case(4)
 80494db:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80494de:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 80494e5:	8b 45 08             	mov    0x8(%ebp),%eax
 80494e8:	01 d0                	add    %edx,%eax
 80494ea:	8b 10                	mov    (%eax),%edx
 80494ec:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80494ef:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 80494f6:	8b 45 0c             	mov    0xc(%ebp),%eax
 80494f9:	01 c8                	add    %ecx,%eax
 80494fb:	8b 00                	mov    (%eax),%eax
 80494fd:	0f af c2             	imul   %edx,%eax
 8049500:	01 45 f4             	add    %eax,-0xc(%ebp)
 8049503:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
# case(3)
 8049507:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804950a:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 8049511:	8b 45 08             	mov    0x8(%ebp),%eax
 8049514:	01 d0                	add    %edx,%eax
 8049516:	8b 10                	mov    (%eax),%edx
 8049518:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804951b:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 8049522:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049525:	01 c8                	add    %ecx,%eax
 8049527:	8b 00                	mov    (%eax),%eax
 8049529:	0f af c2             	imul   %edx,%eax
 804952c:	01 45 f4             	add    %eax,-0xc(%ebp)
 804952f:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
# case(2)
 8049533:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049536:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 804953d:	8b 45 08             	mov    0x8(%ebp),%eax
 8049540:	01 d0                	add    %edx,%eax
 8049542:	8b 10                	mov    (%eax),%edx
 8049544:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049547:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 804954e:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049551:	01 c8                	add    %ecx,%eax
 8049553:	8b 00                	mov    (%eax),%eax
 8049555:	0f af c2             	imul   %edx,%eax
 8049558:	01 45 f4             	add    %eax,-0xc(%ebp)
 804955b:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
# case(1)
 804955f:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049562:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 8049569:	8b 45 08             	mov    0x8(%ebp),%eax
 804956c:	01 d0                	add    %edx,%eax
 804956e:	8b 10                	mov    (%eax),%edx
 8049570:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049573:	8d 0c 85 00 00 00 00 	lea    0x0(,%eax,4),%ecx
 804957a:	8b 45 0c             	mov    0xc(%ebp),%eax
 804957d:	01 c8                	add    %ecx,%eax
 804957f:	8b 00                	mov    (%eax),%eax
 8049581:	0f af c2             	imul   %edx,%eax
 8049584:	01 45 f4             	add    %eax,-0xc(%ebp)
 8049587:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
# 循环条件：--n
 804958b:	83 6d fc 01          	subl   $0x1,-0x4(%ebp)
 804958f:	83 7d fc 00          	cmpl   $0x0,-0x4(%ebp)
 8049593:	0f 8f 91 fe ff ff    	jg     804942a <compute_duff+0x4e>
# 返回
 8049599:	8b 45 f4             	mov    -0xc(%ebp),%eax
 804959c:	c9                   	leave
 804959d:	c3                   	ret
