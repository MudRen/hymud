 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���۵�ͨ�������Ľݾ�����ľΪ�����������������ۻ��ƣ��
���ԣ�����֮�ϵ����֣������ȱ�֮�Ͼ���������ʫ������ɮ�˶���
������д�ڴ˼��ߡ�����ǽ��һ���ر�����עĿ���ഫΪ�������顰��
������������������̨��ʱʱ�ڷ��ã�Īǲ�г�������
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"daxiong",
  "west" : __DIR__"liuzu2",
]));
        set("coor/x",-220);
        set("coor/y",210);
        set("coor/z",40);
        setup();
        create_door("west", "ľ��", "east", DOOR_CLOSED); 
}   
