 inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
һ�˶�ߣ�ֻ�����˲��е�̴��ľ���ȣ����е����������һЩ�滨��ݡ���
�����������ȵ�һͷð������̴ľ�ذ�����ʪ�ֻ����㼸��Ҫ�������˲Ų��Ử
����
LONG
        );
        set("exits", ([
                "south" : __DIR__"jlonglang1",
                "west" : __DIR__"jlonglang3",
        ]));
        set("no_magic",1);
        set("coor/x",-20);
        set("coor/y",40);
        set("coor/z",0);
        setup();
}
void init()
{ 
        add_action("do_search","search");
} 
int do_search()
{ 
        object me,obj;
        me=this_player();
        if(me->query_temp("marks/sword_almost2") && !query("gotit")){
        tell_object(me,"����ʪʪ��ˮ�����������������ڷ�����һ������������\n");
        obj = new(__DIR__"obj/shangfang");
        obj->move(this_object());
        set("gotit",1);
        me->set_temp("marks/sword_gotit",1);
        }else
        tell_object(me,"����ʪʪ��ˮ����������������ʲôҲû��������\n");
        return 1;
} 
void reset()
{ 
::reset();
if(query("gotit") && random(4)) set("gotit",1);
        else set("gotit",0);
        
}   
int valid_leave(object me, string dir)
{
    if(  dir == "west" && (string)me->query("gender") != "����")
        return notify_fail("��������ԡ�ң�����ȥ��ʲô��\n");
    return 1;
}  
