 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
����ɽ�����ģ�ɽɫ���죬��ʱ�����������֮������Զ��һ��Ȫˮ�Ӹ�ɽ��
й���峺��Ȫˮ�����������������γ����ۣ�ÿһ�۴�Ȫˮ���һ��СС��ˮ̶��
����ǻ�ɽ�����Ķ���Ȫ֮һ������Ȫ����
LONG
        );
        set("exits", ([ 
  "eastup"  : __DIR__"zuishi",
  "west"        : __DIR__"mingxuan",
]));
        set("objects", ([
                __DIR__"npc/3que" : 1,
"quest/skills2/wakuang/kuang/kuangmai" : 2,
       ]) );
        
        set("resource/water", 1);
    set("outdoors", "huangshan");
        set("coor/x",-560);
        set("coor/y",-520);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
