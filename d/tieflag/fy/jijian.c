 inherit ROOM;
#include <ansi.h>
int check_legal_name(string arg);
void create()
{
        set("short", "����ͤ");
        set("long", @LONG
������ÿ��ϰ��֮�˱���֮�¡�ÿ��һ��һ�ȵķ��ƳǱ�����������ǲ�����
�˶��ᵽ�������һ�α��У�������ˡ�ͤ�Ӽ䲻������ͨ�磬һ��������ľ��
�ѷ�������������֣�����ʯ�����������һ��ұ��¯��ͨ���¯���ͤ��һ�ж�
Ⱦ��һ���ɫ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ecloud2",
]));
        set("objects", ([
            __DIR__"npc/wangfuren" : 1,
                        ]) );
        set("coor/x",20);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}
