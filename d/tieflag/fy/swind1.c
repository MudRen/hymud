#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�㳡��");
        set("long", @LONG
������Ƿ��Ƶ����Ĺ㳡�������Ƿ��Ƴ��д��˼�ȥ���еıؾ�֮·������
�����˵�������������η��١��������������鱦���˽��˳���ӵ������������
����ר��Ϊ��Ǯ�˵�Զ�����ѵ����Ƴ�����ʱ��׼���ķ���˿�ջ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind2",
  "north" : __DIR__"fysquare",
  "east" : __DIR__"fqkhotel",
  "west" : __DIR__"yuljade",
]));
        set("outdoors", "fengyun");
        set("objects", ([
        __DIR__"npc/mei": 1,
                        ]) ); 
        set("coor/x",0);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
//      replace_program(ROOM);
}  
/*
void init() {
          add_action("do_dazuo","dazuo");
        }
        
int do_dazuo(string arg) {
        object me;
        me=this_player();
        tell_object(me,"�˵ز��ܴ�����\n");
        return 1;
}*/   
