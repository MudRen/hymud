 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ú�ׯ����");
        set("long", @LONG
�����кܿ���������������ľ���������оƣ�����һ��ֽ������Ӵ����ս�����
�����ڼ��ϵ������ϣ�һ����ʮ����Ĵ���������ʮ��ǰ�������������ׯ��Ѧ��
�����̶��������Ѩ����ɨ������ɽ����������������Ǻ���ʮ��ǰһ����������
����ô�ս��������������ķ��Ź⡣----- ���������������أ�
LONG
        );
        set("exits", ([ 
                "north": __DIR__"xuevillage",
        ]));
        set("objects", ([
                __DIR__"npc/xuebin": 1,
                __DIR__"npc/jiaren":    1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
