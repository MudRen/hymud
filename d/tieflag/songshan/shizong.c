 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ʯ�Ȼ���");
        set("long", @LONG
ʯ�Ⱥӷ�Դ����̶������Ⱥɽ�У��γɡ�ˮӪɽ�󡱵ġ�����ʤ
�������������쿴�У�����Ⱥ����̶�ϵġ�ˮƯʯ��֮�ϣ�������
������ʯ�Ȼ����������ڴˡ�����Ħ����Ϊ����֮����֮��������ʯ
���򡱣���Ѧ��д�������Ƿ��ݾ������轡�ʡ���ǧ���δ������
���ˣ����������޲���̾������˳�Ӷ��£�����Ե�����̨һ�Ρ�
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"zhongyue",
  "southup" : __DIR__"guansing",
]));
        set("outdoors", "songshanfy");
        set("coor/x",-170);
        set("coor/y",100);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
