 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�Ͻ�");
        set("long", @LONG
һ���ϱ����С�ֺ����С��Ķ��࣬�����������ٳߡ�С�ֵ�һ�ˣ����ޱ�
�޼ʵĻ�ԭ��С�ֵ���һ�ˣ�Ҳ���ޱ��޼ʵĻ�ԭ�����ڽ��ϣ��������ǽ䱸����
�⣬��Զ��С��û�йٸ���û�к��ţ������˵�һ�ж�Թ��Ψһ���;�����ǳ�
�ʵĵ������ϵ�Ѫ��  
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"mianguan",
                "north": __DIR__"road2",
                "south": __DIR__"street4",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
