//Writen by lnwm
//nongjia2.c

inherit ROOM;

void create()
{
    set("short", "ũ��");
    set("long", @LONG
����һ�Ҽ�ª��ũ�ӣ�������ľͷ���ıڣ���é�ݴ�Ķ������ʮ
�����ҡ�ǽ����Ψһ��һ�ȴ�������һ��ľ�嵲�ϣ������������ʮ�ֲ�
�á����������۾����ܿ�������ڵĳ��裬�������û���ˡ�
LONG
    );
    set("exits", ([
        "east"      :    __DIR__ "lroad4",
        ]));
   
    setup();
}


