// Room: /d/changan/xiaopuzi.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "С����");
	set  ("long",  @LONG
����һ��С���ӡ������ǵ��̡�
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"north"  :  __DIR__"wroad1",
		"south"  :  __DIR__"dangpu2",	
	]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tangxue" : 1,
 
]));	
set("roomif","$botten#��|��|��|����|�鿴����|�鿴�鼮|�鿴����|�鿴����:sell <��Ʒ>|buy <��Ʒ>|redeem <��Ʒ>|value <��Ʒ>|list armor|list book|list misc|list weapon$#");
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -160);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
