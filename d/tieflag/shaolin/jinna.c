 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���۵�����������ͨ������޵��ľΪ�����������������ۻ��ƣ�
�����ȱ�������ʫ���࣬������ܴ���������ڴ˵أ��ر�����עĿ��
�������ס����᱾�������������̨��������һ��δ�Ⱦ��������
������̼���ʫ�����²�������ܣ������㲻���������϶ݣ��Ӵ���
�ڷ�Ϊ�ϱ����ڡ����б��ǽ����޵
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"daxiong",
  "east" : __DIR__"jinna2",
]));
        set("coor/x",-200);
        set("coor/y",210);
        set("coor/z",40);
        setup();
        create_door("east", "ľ��", "west", DOOR_CLOSED); 
}  
