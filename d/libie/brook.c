 // Room: brook.c --- by MapMaker
#include <ansi.h> 
inherit ROOM; 
void create()
{
        set("short", "÷����Ϫ"); 
        set("long", @LONG
��÷�ӡ����������Ϫ��׽��Ϻ�������ֶ����������������
��ҶСϪ��÷�֣�һĻĻ��ʱ�Ŀ����ƺ�������ǰ������ʹ���������ã�
һ�����ϣ�СϪ���ǹ��¿�������������������ʯ����ɫ���������ǰ
Ϫ����Ѫ��ʬ����أ���ֻ��һ����������б��������΢΢������
LONG); 
        set("type","forest");
        set("exits",([
        "north":__DIR__"woods1",
    "southwest":__DIR__"stoneroad4",
        ]) ); 
        set("objects", ([
                __DIR__"npc/master": 1,
        ]) );
        set("outdoors", "libie");
        set("coor/x",70);
        set("coor/y",210);
        set("coor/z",0); 
        setup();
} 
int valid_leave(object me, string dir)
{
        object env, ob; 
        env = this_object();
        ob = present("master yichen", env);
        if(!objectp(ob)) return 1;
        if(!living(ob)) return 1;
        if(me->query_temp("libie/���_׼���ͷ�")) return 1;
        if(me->query("libie/��𹳶�")) return 1;
        if(me->query("libie/���_�ͷ�"))
        {
                me->set("libie/��𹳶�",1);
        return notify_fail(HIY "��һ��̾�����������־��ˣ�����̾��������뾡��Ѱ������ǡ�
"+ RANK_D->query_respect(me) +"���˵�����ĳ�տ������޴󰭣������ȥѰ��������ܷ�����һ��\n֮�����һؽ��ڰ������ס�\n"NOR);
   }
        
                
        if(me->query_temp("libie/���_���ųɹ�")&&dir=="north")
        {
        if(!present("hot rice",me))
        if(present("cold rice",me))
            return notify_fail(YEL "��һ����һ��üë���и�����������ʣ�\n"NOR);
        else return notify_fail(HIY"��һ����һ��üë��û�з���ô�ɣ�\n"NOR);
        if(!present("hot greens",me))
        if(present("cold greens",me))
                return notify_fail(YEL "��һ����һ��üë���и�����������ʣ�\n"NOR);
        else return notify_fail(YEL "��һ����һ��üë��û�в���ô�ɣ�\n"NOR);
        if(!present("hot soup",me))
        if(present("cold soup",me))
            return notify_fail(YEL "��һ����һ��üë���и�����������ʣ�\n"NOR);
        else return notify_fail(YEL "��һ����һ��üë��û������ô�ɣ�\n"NOR);
        me->set_temp("libie/���_׼���ͷ�",1);
        return notify_fail(HIY "��һ��������һ�������ŵķ��ˣ����΢΢Ц�����ú��ӣ�ȥ�ա�\n"NOR);
        } 
    if( !me->query_temp("libie/���_��ͷ")){
        if( !(me->query("libie/���_����")) && (dir == "north")){ 
                me->set_temp("libie/���_��ͷ", 1);
                message_vision( HIR "\n��һ����Ѫ������������ס$N��ȥ·��������Ц����
��ĳ�˵���һ�����ڣ������ö������ӴӴ˶�����\n"NOR, me); 
                        return notify_fail("");
                }
    } else {
        if( !(me->query("libie/���_����")) && (dir == "north")){
        add_action("do_answer", "answer");
        message_vision(HIR "\n��һ������·�У�����ض���$N��һ��һ�ֵ����������ǲ�����(answer yes or no)\n"NOR, me);
        return notify_fail("");
        }
        }
        return 1;
}  
                 
int do_answer(string arg)
{
    object ob, me;
    ob = present("master yichen", environment(this_player()));
    me = this_player();
    if(objectp(ob))
    if(living(ob))
    if( arg == "yes" )
    {
        message_vision(YEL "��һ�����˵�ͷ��˵�����Ƿ�֮�أ��㻹�ǹ���ԽԶԽ�á�\n"NOR, this_player());
        return 1;
    }
    else if( arg == "no" )
    {
        message_vision(HIR "��һ������һ����˵�����������Ǿ������ɣ�\n"NOR, this_player());
        ob->kill_ob(this_player());
        me->set_temp("libie/���һ", 0);
        return 1;
    }
    else
    return 0;
}   
