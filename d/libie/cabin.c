 // Room: cabin.c --- by MapMaker
#include <ansi.h>
inherit ROOM;  
int resleep(object ob);
void create()
{
        set("short", "Сľ��"); 
        set("long", @LONG
���Ǽ��ƾɶ���ª��Сľ�ݣ�����ʰ�ĸɸɾ�����ľ����ֻ��
һ��һ��һ�Σ��������룬һյ�ߵƺ�һ������Ļ�¯��ÿ������
�����ƾɡ�����һ��ƣ�벻��������Ů������һ�㾲��˯�š���
���ϰ��˼��뷹�ˣ������Ա�ѹ���ű�ǩ��
LONG); 
        //{{ --- by MapMaker
        set("type","house");
        set("exits",([
        "south":__DIR__"woodsedge",
        ]) );
        
        set("objects", ([
        __DIR__"npc/lusuwen": 1,
        ]) );
        set("indoors", "libie");
        set("coor/x",70);
        set("coor/y",240);
        set("coor/z",0);
        
        //}} 
        setup(); 
}  
void init()
{
    add_action("do_look","look");
}  
int do_look(string arg)
{       
    object lusuwen, me;
    
    me=this_player();
    
    if (arg=="����"||arg=="table")
    {
        tell_object(me,"һ���ƾɵ�����������ӣ�����������뷹��һ����ˣ�һ��ù������һ�����⣬\n��˫��������İ��ڷ����Աߡ����˶�һ��û�ж�������������Ѿ�����˵�\n������ֱ����ոն������������ӡ�����һ�������Աߣ�����һ��С�ƺ�����\n�����Ա���һ��ֽ�㡣\n");
        me->set_temp("libie/���_���",1);
        return 1;
    }
    if (this_player()->query_temp("libie/���_���")&&(arg=="ֽ��"||arg=="sheet"))
    {
        tell_object(me,GRN "һ�ŵ��ŵ�ֽ�㣬���飺
        
������ɣ� 
�����ȥ���գ����顣���С�����Ϸ���������ա���������ɹ�ʳ�� 
                                                     ����\n"NOR,this_player());
        me->set_temp("libie/���_ֽ��",1);
        return 1;
    }
    if (lusuwen=present("lu suwen",this_object()))
    if (!living(lusuwen))    
    if (lusuwen->query("disable_type")==HIG"<˯����>"NOR)
    if (me->query_temp("libie/���_ֽ��")&&(arg=="������"||arg=="lu"||arg=="lu suwen"))
        {
        tell_object(me,"�������������������ƺ����Ի��ѣ������壩�����ӡ�\n");
        add_action("do_wake","wake");           
        }
        
    return 0;
} 
int do_wake(string arg)
{
        object ob,me;
        
        if(!arg) return 0;
        ob=present(arg,this_object());
        me=this_player();
        if(!ob) return notify_fail("����û������ˡ�\n");
        if(ob->query("id")=="lu suwen")
        {
                remove_action("do_wake","wake");
                ob->start_call_out( (: call_other, ob, "wake" ,me:), 0);
                if(me->query_temp("libie/���_׼���ͷ�") && present("hot rice",me)
                           &&present("hot greens",me)&&present("hot soup",me)) {
                        ob->start_call_out( (: call_other, ob, "ask_question" ,me:), 3);
                } else {
                        ob->start_call_out( (: call_other, ob, "sleep" :), 20);
                }
                return 1;
        }
        return 0; 
}  
                    
int valid_enter(object me)
{
        object lu,yang;
        int finale; 
        if(!me->query("libie/���_β��")&&lu=present("lu suwen",this_object())) 
        if(finale=me->query("libie/���_ɱ��������"))
        {  
                if(finale==1)
                {
                        set("���1����",me);
                        me->set_temp("���_Ŀ�������",1);
                        if(!living(lu))
                                lu->start_call_out( (: call_other, lu, "wake" ,me:), 2);                
                        lu->start_call_out( (: call_other, lu, "dying", me:), 5);               
        
                }
                if(finale==2)
                {       
                        set("���2����",me);
                        me->set_temp("���_Ŀ�������",1);
                        yang=new(__DIR__"npc/yangzheng2");
                        yang->move(this_object());
                        lu->die();
                        me->start_call_out( (: call_other, yang, "dying" ,me:), 3);
                }
        }
        return 1;
}        
int valid_leave(object me,string dir)
{
   if(me->query_temp("���_Ŀ�������"))
                return notify_fail(HIY"�����뿪������ʹ����ȴ�������Ų���\n"NOR);
        return 1;
} 
void reset(){
        object ob;
        ::reset();
        if(ob = present("lu's corpse", this_object())){
                destruct(ob);
        }
        if(ob = present("yang's corpse", this_object())){
                destruct(ob);
        }
} 
