#include <room.h>
 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��ô������ӣ�ֻ��һ����������С�Ĵ�������غܸߡ������ǹ��ŵģ�����
������ľ�ɫ����Ҳ��С�����Կ���ˣ���ֻ�ܲ�����롣ǽ�����Ű�ɫ���ᣬ��
�úܺ񣬷·�Ը�˿�����ǽ��ʯ�ڣ�����������ͭ�������������������Ŵ���ľ
�������ϵı���ܸɾ���ȴ�ܼ��ӡ�����֮�⣬����ֻ��һ�źܴ�����ӡ�������
�����˸�ʽ�������˲�;��ڡ�û�����ӣ���һ�����Ӷ�û�С�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jhuang1",
]));
        set("objects", ([
        __DIR__"npc/jinwuming" : 1,
        __DIR__"npc/shangguan" : 1,
                        ]) );
        set("valid_startroom", 1);
        set("coor/x",-20);
        set("coor/y",-30);
        set("coor/z",0);
        setup();
        create_door("north", "��ͭ��", "south", DOOR_CLOSED); 
}
