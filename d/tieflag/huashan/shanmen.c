 inherit ROOM;
void create()
{
    set("short", "�ϱ�ɽ��");
    set("long", @LONG
ɽ���Խ�����ǰһ��ʯ��������ʯ�����顰��ɽ������������֣�ʯ�ź�ɽ����
��ͦ�Σ���ͷ�����͵��ָ������ƣ�һ����ʯС·����ɽʯ����������ȥ��С·��
������ڵ�ë�������������һƬ��䣬����������ˬ���ڿ��ȵ��������
·�������ܹ���һ��ô��һ���ط�Ъ�ţ�ʵ�ںܲ���
LONG
        );
    set("exits", ([ 
                "north" : __DIR__"road4",
                "south" : __DIR__"xiaojing",
        ]));
        set("objects", ([
                __DIR__"npc/fatman1" : 1,
                __DIR__"npc/xiaobao" : 1,
        ]));
    set("outdoors", "huashanfy"); 
    set("coor/x",-560);
    set("coor/y",-20);
    set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
