 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "Сʯ��");
        set("long",  @LONG
˵��ʯ������ʵֻ��ʯ����һ�鰼���ĵط�������ڹ�¡�˵����ֲ�
����ָ�������ϲ�ͣ����ˮ�����������ھ���͸�ĵ��������²ȵ�����Ӳ
Ӳ�Ķ�����˳������ȥ��������һ����­��ż�����м�ֻ���������ų��
�ɹ�����ڣ�ѹ�֣�ʹ���̲�ס����������С�
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"yongdao2",
        ]));
        set("objects", ([
                __DIR__"obj/woodbarrel" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
