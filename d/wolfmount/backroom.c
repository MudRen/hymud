 inherit ROOM;
void create()
{
        set("short", "����"); 
        set("long", @LONG
�������Ǹ�С����һ����ľ��̨�ϰ����Ż�Ƥ�Σ�һ����ɫľȻ������������
����һ��������������������һ�ֹ����Ũ�ҵ�̴��ζ��
LONG);
        set("type","indoors");
        set("exits",([
                "north":__DIR__"shuaiyi",
        ]) );
       set("indoors", "wolfmount");
        set("objects",([
                __DIR__"npc/zhuwu":1,
                __DIR__"npc/kunlun1":1,
                __DIR__"npc/kunlun2":1,
        ]) );
        set("coor/x",-640);
        set("coor/y",-830);
        set("coor/z",100);
        set("no_magic",1);
        setup();
        replace_program(ROOM);
}      
