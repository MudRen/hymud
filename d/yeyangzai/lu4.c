// Room: /open/stst/sazai/lu4.c

inherit ROOM;




void create()
{
	set("short","Ұ��կ�ⷿ");
        set("long", @LONG
	�����Ұ��կ�Ŀⷿ�������ӵĹ��Ӻͼ��ӡ�������������ҳ������
����Щ���������ߣ�������ò鿴һ�¡�������Ұ��կ��ͬһ���Ļ�����
�������ȡһЩ����������������Щ�������������ģ�һ�㶼�޷�������
LONG

        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"qianting",
]));
	set("objects",([
		"clone/weapon/gangdao":1,
		"clone/weapon/gangjian":1,
		"/d/city/npc/obj/jitui":1,	
		"/d/city/npc/obj/baozi":1,	
		"/d/city/npc/obj/jiudai":1,			
		__DIR__"npc/obj/banfu":1,
		__DIR__"npc/obj/tongjia":1,
__DIR__"npc/obj/gangjia":1,
					
]));
        setup();
}

