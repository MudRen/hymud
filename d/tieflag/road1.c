 //road1.c
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
ת��һ��ɽ�꣬���������Բԣ���ɽ��ľ������ɽ�廷����
�·�������·�����ܼ���������ż��һ����������ʱ��ʱ�ϵ�
ˮ�����ƺ�ʲôҲ��������
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"road0",
  "northup" : __DIR__"outroom",
]));
        set("outdoors", "tieflag");
        set("coor/x",60);
        set("coor/y",2000);
        set("coor/z",20);
        setup();
}
void init()
{
        add_action("do_listen","listen");
}
int do_listen(string arg)
{
        object bird;
        if(!query("already"))
        {
        tell_object(this_player(),"����ϸ�������������㣢��һֻСɽȸ�������з��˳�������\n");
        bird = new(__DIR__"npc/littlebird");
        bird->move(this_object());
        set("already",1);
        return 1;       
        }
        else
        return 0;
}
void reset()
{
::reset();
delete("already");
}     
