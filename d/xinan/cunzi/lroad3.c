//Writen by lnwm
//lroad3.c

inherit ROOM;

void create()
{
    set("short", "С��·");
    set("long", @LONG
���е�С·����Ϊ������ɽ���������Ե�·����ƽ����ʱ����ʱ����
����������������಻֪����С����������ߴߴ�����ؽ��š��㲻����
��Ҳ�������������Ų�Ҳ����ˡ�����·�ľ�ͷ��һ��ũ�ᣬԶԶ��ȥ��
������š�������һ��С��԰��Ҳ��֪��˭�ҵ�.
LONG
        );
    set("outdoors","lnwm");
    set("exits", ([
        "southeast"     :       __DIR__ "lroad2",
        "northwest"     :       __DIR__ "chaimen",
        "southwest"     :       __DIR__ "caiyuan2",              
                ]));
    
    setup();
    replace_program(ROOM);
}


