// Roon: ziqitai.c
//Date: Oct. 2 1997 by Venus
inherit ROOM;

void create()
{
        set("short", "����̨");
        set("long", @LONG
����̨�����������ڣ����ɲ������գ���Ϊ������ǣ�û������
�죬ɽ��֮�о��������������֡�
LONG);
        set("outdoors", "xx");
        set("exits",([ /* sizeof() == 1 */
            "eastdown": __DIR__"chaopath2",
        ]));
        set("no_clean_up", 0);
        setup();
}
