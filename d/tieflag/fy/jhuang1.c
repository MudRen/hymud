#include <room.h>
 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���¾���ר�Ÿ����Ǯ���ܶ�İ�ȫ���������˶�Ҫ�������ǵ���ϸ�̲顣��
���������ְ���Ϣ�����ڡ������м���С��������С����ÿ�Ŵ�ͷ����С��������
�Ƕ��ѱ������ڹ��ϣ�һ���־Ϳ����������ٶȰγ��Լ��ı��С�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jting",
  "south" : __DIR__"jbang",
]));
        set("objects", ([
        __DIR__"npc/huangyi2" : 1,
        __DIR__"npc/huangyi" : 2,
                        ]) ); 
        set("coor/x",-20);
        set("coor/y",-25);
        set("coor/z",0);
        setup();
        create_door("south", "��ͭ��", "north", DOOR_CLOSED); 
}  
