// By River@SJ 2001/9  

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
���������Ͼ��Ͽ��������������������ǳ����֡���ʱ�����������������
�߷ɳ۶���������һ·��������·��������������������֡������Ѿ�������
���������ǵĳ����ˡ�
LONG
        );
        set("outdoors", "tanggu");
        set("exits", ([ 
                "east" : __DIR__"ximen",
                "southwest" : __DIR__"wroad2",
        ]));

        set("no_clean_up", 0);

        setup();
}