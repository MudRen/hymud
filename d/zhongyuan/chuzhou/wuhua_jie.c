// �����ﻪ�� /d/city/chuzhou/wuhua_jie.c
// by lala, 1997-12-04

inherit ROOM;

void create()
{
    set("short", "�ﻪ��");
    set("long", @LONG
�ﻪ�ֺͳǱ����챦·���Ӧ����ȡ���ﻪ�챦��֮�⡣�������������ߣ�
�Ϳ��Գ���������ȥ���ݳǵĴ�·�ˡ��ֱ�����ƽ�֣�����һ����Ц����������
�Ǽҵ��̣���������������������滨����Ǯ�Ƶ��˲��ò�������ȥ����ؼҵ�
�̲����ֵĶ����Ǽ��ھ֣��ſڶ���һ��ʯʨ�ӣ�����ɫ�������������Ʈ�ţ�
����д���ƺ��ǡ������������֡�
LONG
    );
    set("outdoors", "yangzhou");
    set( "no_kill",  "yangzhou" );
    set("exits", ([
        "east"      : __DIR__"biaoju",
        "southeast" : __DIR__"nan_men",
        "north"     : __DIR__"shengping_jie",
        "west"      : __DIR__"dangpu",
    ]));
    set("objects", ([
    ]));
    setup();
}
