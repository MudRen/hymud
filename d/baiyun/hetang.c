 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�������棬��������������������ġ��������۵ĺ������棬�������������
Ҷ�ӡ�Ҷ�ӵ�������������ˮ�����ܼ�һЩ��ɫ����Ҷ��ȴ���������ˡ�����Ҷ
���м䣬���ǵص�׺��Щ�׻�������Ų�ȵؿ��š�΢������������������㣬һ��
���ض��ļš�
LONG
           );
        set("exits", 
           ([ 
       "up" : __DIR__"9bridge",
       "down" : __DIR__"shishi",
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
