 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���������£�����ɽ������֮�أ�ռ������ƽ���ף���������
��ʱǧ��Ķ��ַ��ɣ���ɮ������ڴˣ����СС���ٶ�ʮ����
שʯĹ��������������ǰ�ķ�ѧ��λ�������ȵȴ�С��һ�����²�
һ�������š�Ĺ�����͸��죬���о��Ŵ�שʯ��������������ı�
�⣬��Ϊ�����ı������ú��о͹�������ɮ�ľ�������
LONG
        );
        set("exits", ([ 
  "east" : "/d/tieflag/shaolin/houmen",
  "northeast" : __DIR__"huishan",
  "northwest" : __DIR__"damo",
  "south" : __DIR__"erzu",
]));
        set("outdoors", "songshanfy");
        set("objects", ([
                __DIR__"obj/ta1" : 1,
                __DIR__"npc/lama3" : 1,
       ]) );
        
        set("coor/x",-220);
        set("coor/y",410);
        set("coor/z",70);
        setup();
        //replace_program(ROOM);
}     
int valid_leave(object me, string dir)
{
	if ( objectp(present("pan deng", environment(me))) && 
		dir == "south")
		return notify_fail("�̵��ڶ���ס�����ȥ· ��׼��������ɣ����Ĵ��¡�\n");


	return ::valid_leave(me, dir);
}