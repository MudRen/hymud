 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "�Ž�С��");
        set("long", @LONG
һ��������Щ�ɺԵ�СϪ���Ǽ�ܼ�ª��С�ݣ���Щ������֦���ܣ���鵰Ž�
��Ҷ�����ݶ�������������̫�ѿ�����Ҳ���з�ζ��һЩ����Ĳ����ڵ���Ȩ����
����һ��Ц���е����ӷ�������������������档é�ݱ���Щ���͵���ʯ�����Ƭ
ľ�顣����С�ݣ���Ȼ�Ǹ������ɽ�ȡ�
LONG
           );
        set("exits", 
           ([ 
       "north" : __DIR__"shangu",
       "south" : __DIR__"shatan",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("indoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}   
