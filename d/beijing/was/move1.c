inherit ROOM;

void create()
{
        set("short", "Ԫ�󶼳�����");
        set("long", @LONG
������Ԫ�󶼳ǵ����ģ�Ҳ���Ǻ��������ǵ�ǰ����ɫ�ĳ�ǽ������ׯ
������֮�У�ԶԶ��ȥ����¥�������淢�Ե���ΰ�ߴ�һ�����Ǻ��ƳǶ�����
LONG );
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg",1);


        set("outdoors", "beijing");
        setup();
        replace_program(ROOM);
}


