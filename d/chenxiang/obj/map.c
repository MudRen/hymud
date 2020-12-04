#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"�ر�ͼ"NOR, ({ "map" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ���������Ƥ�ر�ͼ������Զ�һ��������䣩��\n");
          } 
        
}
void init()
{
        if(environment(this_object())==this_player())
        add_action("do_read","read");
        add_action("do_go","go");
} 
int do_read(string arg)
{
        object me;
        mapping exits;
        string *dirs;
        string thisdir;
        if(arg != "map") return 0;
        me=this_player();
        if(find_call_out("markit")== -1)
        call_out("markit",random(60)+20,me);
        if (query("already"))
        {
                return notify_fail("��ȸͼ�еĶ����ƺ������˵õ��ˡ�\n");
        }
        if( !mapp(exits = environment(me)->query("exits")) ) 
        {
                tell_object(me,"��ȸͼ�����ڸ�����\n");
                return 1;
        }
        dirs = keys(exits);
        thisdir = dirs[random(sizeof(dirs))];
        set("thisdir",thisdir);
        tell_object(me,"��ȸͼ�ƺ�Ӧ����"+thisdir+"�ķ���\n");
        return 1;
} 
int do_go(string arg)
{
        if(arg==query("thisdir"))
        this_player()->add_temp("going",1);
        return 0;
}
int markit(object me)
{
        object design;
        if(me->query_temp("going") <= 10 || environment()!=me) return 1;
        if(!query("already"))
        {
        design = new("/d/tieflag/obj/design");
                tell_object(me,"\n��һ�������ӡ��ر�ͼ����ָʾ�ĵط��ڳ���ȸͼ��\n");
                design->move(me);
                me->delete_temp("going");
                set("already",1);
        }
        return 1;
}    
