//Writen by lnwm
//lroad5.c

inherit ROOM;

void create()
{
    set("short", "С��·");
    set("long", @LONG
���Ӻ�С���㷢��û�������͵���·�ľ�ͷ������Ҳ�����Ǵ��ӵľ�
ͷ����������ɽ�£�Ҳ�����ɽ��һ���֣�ɽ������һ��С���֣����ܴ�
�Եؿ�������ͷ��������������һ��Сé�ݣ�����������û��ס�����ӡ�
������Ҳ��һ��ũ��.
LONG
        );
    set("outdoors","lnwm");
    set("exits", ([
        "south"         :       __DIR__ "lroad4",
        "north"         :       __DIR__ "shulin",
        "northeast"     :       __DIR__ "maowu",
        "northwest"     :       __DIR__ "nongjia1",              
                ]));
    
    setup();
    replace_program(ROOM);
}


