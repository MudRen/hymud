 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����£���������������ɽ��֮�У���Ȼ����˶࣬�������
�ɻ���ʵ�������������š����̵�̶ˮ�������طۺ�ĺɻ�������
������Ȼ�����޽�ڻԻ�֮�ޡ�
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"erzu",
  "southdown" : __DIR__"qingliang",
]));
        set("objects", ([
                __DIR__"npc/lama1" : 1,
       "/d/taoyuan/npc/rabbit": 2,
       ]) );
        set("coor/x",-220);
        set("coor/y",390);
        set("coor/z",60);
        setup();
        //replace_program(ROOM);
}       

int valid_leave(object me, string dir)
{
	if ( objectp(present("bo luo", environment(me))) && 
		dir == "southdown")
		return notify_fail("���޸�����ס�����ȥ· ��׼��������ɣ����Ĵ��¡�\n");


	return ::valid_leave(me, dir);
}