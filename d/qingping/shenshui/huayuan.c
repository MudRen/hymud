 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
�����ŵ������������㣬ԭ���ڴ˴��и�ŵ��ĺ�԰����ˮ������
ɽ��������ȴ�ֻ�Ȼ���ʣ��������һ��СС�Ĺȵأ�԰���ʻ�������������
�ǣ��ڴ��ɾ�֮�У��򸴺��󡣶���һ�����Ƶķ��ӣ�����ȥʮ�ֵĿ���
LONG
        );
        set("outdoors","shenshui");
        set("exits", ([ 
  "west" : __DIR__"cangjian",
  "north" : __DIR__"guayu",
  "east" : __DIR__"shufang",
  "south" : __DIR__"qingong",
]));
   set("objects", ([
      __DIR__"npc/qinggirl": 1,
      __DIR__"npc/xiang": 1,
   ]) );
        set("coor/x",190);
        set("coor/y",12360);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}     
