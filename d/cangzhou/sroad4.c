// By River@SJ 2001/9  

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
��������Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG
        );
        set("outdoors", "cangzhou");
        set("exits", ([ 
                "northwest" : __DIR__"sroad3",
                "south" : "/d/ruzhou/ruzhou",
"east" : "/d/shaolin/shang_road1",
        ]));
        set("no_clean_up", 0);

        setup();
}
