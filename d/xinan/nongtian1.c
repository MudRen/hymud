#include <room.h>
inherit ROOM;


void create()
{
        set("short", "ũ��");
        set("long", @LONG
������Ⱥɽ������һ�����أ������˳���Ϊ�����ӡ�������ɽ��ƽ�أ��ȵ�
����˼���󲿷��ϰ��ն��۾���һ����ɢ�ġ����ӡ��ϡ��������ط��֣�ˮԴ
��֣�����ƽ̹���˸��֡�������ï�ܵ�ԭʼɭ�֣�����ȥ��ɭɭ�ģ�����Ϳ�
��������Ĺ����ˡ�
    ·��ˮ�������������æµ��
LONG
        );
        set("exits", ([
                "west"     : __DIR__"erhai",
                "east"     : __DIR__"milin1",

        ]));
        set("outdoors","xinan");
	set("objects",([
		__DIR__"npc/cunmin" : 2,
		]) );
        setup();
}
/*
int valid_leave( object me,string dir)
{
// object ob;
    if( dir == "south")
    {
        tell_object(me,"��������Ц�����Ǻǣ���ȥ�������ɽ�ˣ����ڻ�û�������أ�\n");
        return notify_fail("��ֻ����ס��\n");
    }
    return ::valid_leave(me,dir);
}
*/
