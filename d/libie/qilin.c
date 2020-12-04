 // Room: qilin.c --- by MapMaker
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "�����"); 
        set("long", @LONG
��ν�������ʵֻ��һ��ܿ��������ӣ��ı�ѩ���޳����ú�
ľ�̳ɵĵ��棬���˲��ʵ���ص��廨��̺��������ʲô��û�У�ֻ
���������š�
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "out":__DIR__"corrider",
        ]) );
        //}}
     set("objects", ([

        "/kungfu/class/honghua/luo-bing" : 1,
    ]) );                
        set("indoors", "libie");
        set("coor/x",40);
        set("coor/y",180);
        set("coor/z",10);
        set("no_fly",1); 
        setup();
}  
/*
һ���Ŀ���ߣ���ϥ����һ�������ϣ�ϥͷ�Ϻ�ڸ���
���ȣ��·�����ɮ�붨��������������һ�����ŵ����ߣ�ǹһ��վ��
���������ˡ�
*/
void init(){    
        add_action("do_kill","kill");
} 
int valid_enter(object me)
{
        object ying,yang,di;
        object room;
        
        room=this_object(); 
        if(me->query_temp("libie/���_׼����������")) {             
           me->delete_temp("libie/���_׼����������");
        }
        if(me->query_temp("libie/���_��ֹ���������")) {
                me->delete_temp("libie/���_��ֹ���������");
        }       
        if(query("�������"))
                return notify_fail(HIR"�������ڴ��޴�����絲���������ǰ��͸�����磬��ֻ�������洫������ɱ����\n"NOR); 
        if (!me->query("marks/���") && me->query("libie/��𹳶�")
                &&      me->query("libie/���_С���ӵľ���")
                &&      me->query("libie/ĥ������"))
                me->set_temp("libie/���_����ֿ�ʼ",1); 
        if (me->query("libie/���_ɱ��������")==1
                || me->query("libie/���_ɱ��������")==2)
                me->delete_temp("libie/���_����ֿ�ʼ");
        
        if(me->query_temp("libie/���_����ֿ�ʼ"))
                {
                
                set("�������",me);
                me->delete_temp("libie/���_����ֿ�ʼ");
                if (objectp(di=present("di qinglin",room)))
                        destruct(di);
                if(!objectp(di=present("di qinglin",room)))
                {
                        di=new(__DIR__"npc/diqinglin");
                        di->move(room);
                }
                if(!objectp(ying=present("ying wuwu",room)))
                {
                        ying=new(__DIR__"npc/yingwuwu");
                        ying->move(room);
                }
                ying->start_call_out( (: call_other, ying, "do_busy", me :), 1);        
                if(!objectp(yang=present("yang zheng",room)))
                {
                        yang=new(__DIR__"npc/yangzheng");
                        yang->move(room);
                }
                yang->start_call_out( (: call_other, yang, "do_rival", di :), 1);                       
                
   }
        else
        {
                if(!objectp(di=present("di qinglin",room)))
                {
                        di=new(__DIR__"npc/diqinglin2");
                        di->move(room);
                }
                di->start_call_out( (:call_other,di, "greeting", me:),1);
        }
        return 1;
} 
int do_kill(string arg)
{
        object me,yang,di,ying,room;
        
        room=this_object();
        me=this_player();
        if(!present(arg,room)) return 0; 
        if(present("yang zheng",room)&&present("di qinglin",room))
        {
                write(HIW"�㱻�������˵�ɱ�����壬��Ȼһ��Ҳû������\n"NOR);
                return 1;
        }
        return 0;
} 
int valid_leave(object me,string dir)
{
        object yangcorpse;
        
        if(dir!="out") return 1;
        if(query("�������")) delete("�������");
        if(present("di qinglin",this_object()))
                return notify_fail(HIR"������΢Ц�Ķ���˵��������ߣ��ò�����ô���ɣ���\n"NOR);
        if(me->query("libie/���_ɱ��������")==1)
        {       
                if(objectp(yangcorpse=present("yang's corpse",me)))     
                        return 1;
                if(present("yang's corpse",this_object()))
                        return notify_fail(HIY"�㿴����������Ŀ��ʬ�壬���÷�������δ�����Ĳ��̡�\n"NOR);
   }
        return 1;
}
