 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ɽ��");
        set("long", @LONG
ɽ���������ϣ�Զɽ�ǿݻ�ɫ�ģ�����Ҳ�ǿݻ�ɫ�������ɫ�Ĳ���£�����
�������ض����޵������������Ҷ���ʣ������������ʱ�Ŀ�����Զ���ƺ����˵�
�̷�ţ����Ȿ���������̵ĵط���Ȼ��һ�����£��������¾�Ȼ��������������
����ʱ��Ҫ̾һ������÷���֡�
LONG
        );
        set("exits", ([ 
                "southdown" : __DIR__"road2a",
                "westup": __DIR__"meihuaan",
        ]));
        set("objects", ([       
        ]) );
        set("outdoors", "eren");
        set("coor/x",-1260);
        set("coor/y",2030);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}   
