#include <ansi.h>
inherit NPC;
void dreamsay();
void create()
{
        set_name("������", ({ "lu suwen","lu" }) ); 
        set("gender", "Ů��" );
        set("age", 22);
        set("str", 100);
        set("per", 50);
        set("long", @LONG
һ�����£����ĸɸɾ����������������һ�ű������㶯�˵�������
������Щ�������ƣ�롣
LONG
); 
        
        set("combat_exp", 10); 
        set("attitude", "friendly"); 
        setup();
        this_object()->disable_player( HIG "<˯����>"NOR);
//      this_object()->set_temp("is_unconcious",1);
//      set_temp("block_msg/all", 1);
//      COMBAT_D->announce(this_object(), "unconcious"); 
        carry_object(__DIR__"obj/white_cloth")->wear();
} 
int accept_fight(object me)
{
        command("emote ˯�����㣬һ�㷴Ӧ��û�С�");
        return 0;
}  
void init()
{
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);
        add_action("do_answer","answer");       
        if(!living(this_object()))
        if(!query("��ʼ˵�λ�"))
        {
                set("��ʼ˵�λ�",1);
        call_out("dreamsay",10+random(100));
        }
   ::init();
} 
void dreamsay() 
{       object room; 
        if(!living(this_object())&&this_object()->query("disable_type")==HIG"<˯����>"NOR)
        {
                room=environment(this_object());
                message("vision",HIG "�����ķ����������Ľ�ë�����Ҹ�����⣬˯�����૵������Ŷ��������ˣ�\n�������ˡ����������ȥ�ȡ���\n"NOR,room);
                call_out("dreamsay",10+random(100));
        }
        else
                delete("��ʼ˵�λ�");
        return;
} 
void heart_beat()
{
        int msg;
        object me,lu,sheet;
         
        if(!living(this_object())&&this_object()->query("disable_type")==HIG"<˯����>"NOR)
        if(!query("��ʼ˵�λ�"))
        {
                set("��ʼ˵�λ�",1);
                call_out("dreamsay",10+random(10));
        }
        if(msg=query("dying_msg"))
        {
                me=environment()->query("���1����");
                lu=this_object();
                if(msg==4)
            message_vision("$Nƽ�����ʣ��ҷ���ǲ����Ѿ����������ˣ�\n",lu);
                if(msg==3)
                        me->ccommand("hmm");
                if(msg==2)
            message_vision("$N���������룬������߽�������ɡ����������ˡ���\n
�����ĵ�����Խ��Խ΢��������\n",lu);
                if(msg==1)
                {
            message_vision(HIG"\n$N����˯���ˣ�ƣ�������¶�������΢Ц������
΢��������̾Ϣ������ɹ���ȸ���ڵ͵���ౣ�һ�й������š�����\n"NOR,lu);
                   sheet=new(__DIR__"obj/sheet");
                        sheet->move(this_object());
                        me->set("libie/���_β��",1);
                        lu->die();
                }
                add("dying_msg",-1);
        }
        ::heart_beat();
} 
void sleep()
{
        message("vision","�����Ĵ��˸���Ƿ������˯�˹�ȥ��\n",environment());
        this_object()->set_temp("is_unconcious",1);
        this_object()->disable_player(HIG "<˯����>"NOR);
} 
void wake(object me)
{       string msg;
        object room;
        
        
        this_object()->delete_temp("is_unconcious");
        this_object()->enable_player();
        room=environment();
        if (present(me->query("id"),room)) 
                message_vision(HIG"����������˫��������һ��������$N��\n"NOR,me);
        else message("vision",HIG"����������˫��������һ����\n"NOR,room); 
} 
int dying(object me)
{
        set("dying_msg",4);
        heart_beat();
        return 1;
} 
void die()
{       object me,corpse,*inv,room;
        int i; 
        room=environment();
        if(me=room->query("���1����"))
                me->delete_temp("���_Ŀ�������");
        corpse=new("/d/libie/obj/lucorpse");
   corpse->move(room);
        inv=all_inventory(this_object());
        i=sizeof(inv);
        while(i--)
                inv[i]->move(corpse);
        message_vision("����������\n",this_object());
        destruct(this_object());
                
}  
int ask_question(object me)
{       
        if(environment(me)!=environment()) return 0; 
    message_vision(HIY "�����Ŀ��������������ķ��ˣ�������˼���������½���ɫ��������
��������������ʳ�İɣ�(answer yes or no)\n"NOR,me);
        this_object()->set("add_answer",me);
        return 1;
} 
int do_answer(string arg)
{
    object ob, me, book;
    ob = this_object();
    
    if(!ob->query("add_answer")) return 0;
    me = ob->query("add_answer");
    if (objectp(ob))
    if( living(ob))
    {
    if( arg == "yes" )
    {
        if(!me->query("libie/���_�ͷ�")){
        message_vision(HIY "�����ĵ��˸��򸣣���˼Ƭ�̣�ȡ�������ƹ����$N����λ"+RANK_D->query_respect(me)+"��ʳ֮������
��Ϊ���������ҷ���ġ�����ס�����������°ɡ�\n"NOR, me);
        book=new(__DIR__"obj/swordbook");
        if(book) {
                book->move(me);
        }
        me->set("libie/���_�ͷ�",1);
        message("vision",HIC "������΢Ц���ᶨ��˵��˳����¸�֪�������������������ģ�����ֻ
���ҷ��ɹ�����\n��������ȼ������ֱ�Ŀ���\n"NOR,me);
                } else {
           message_vision(HIY "�����ĵ�����������Ѿ��������벻�ض��ԡ�\n"NOR,me);
        }
    } else if( arg == "no" ) {
        message_vision(HIG"������΢̾һ������Ŀ���\n"NOR, me);
    }
    remove_action("do_answer","answer");
    me->delete_temp("libie/���_׼���ͷ�");
    return 1;
    }
    
    return 0;
} 
