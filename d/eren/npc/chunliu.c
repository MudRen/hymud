#include <ansi.h>
inherit NPC;  
void create()
{
        
        set_name("����",({"wan chunliu","chunliu"}));
//      set("title","��������");
        set("nickname",HIG"��ҽ"NOR);
        set("long", "���˱������𽭺��ġ����ֻش�����ҽ��������˵ֻҪ���߻���һ
�����ڣ�������ҩ��������\n");
        set("age",45);
        set("attitude", "friendly");
        set("combat_exp", 4000000);
                        
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1500);
        set("neili",1500);
                
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("inquiry", ([
                "��֦һҶ��" : "�˻���Ϊ���������л������ܵõ���",
                "flower" : "�˻���Ϊ���������л������ܵõ���",
                "��������" : "��һ����֦һҶ������˵����������֮��Ч��",
                "qisihuisheng" : "��һ����֦һҶ������˵����������֮��Ч��",
                 "С��" : "С���Ǵ���ĺ��ӡ�",
                 "ŷ��������" : "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ŷ����" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ŷ����" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ouyang ding" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ouyang dang" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "������¥": "������¥��Ȼ�ǹ���������ඣ���˵���������ⲻ�ã�����Ϊԭ�Ϸ����ء�",
                "������ջ": "������ջ����������Ů�����ġ�",
                "��С��": "������ջ����������Ů����С�����ġ�",
                "���˹�": "������ǵ���Ķ��˹ȡ�",
                "������": "��С����뻨��ȱ�����������׺���������뿪�����ˡ�",
                   "����": "�������¡�",
                "���ϵ�": "���ϵ�ר��������˵Ҫ�����İ���������ѧ������������С�",
                "��ԯ����": "�����ֻʣ���Ǽ䵱���ˡ�",
                "��Ƽ��": "������Ů����һ����ס���Ƕ����ֿ����ġ�",   
        ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "������ͷ��˼�������û����ʶ����Ĵ��ڡ���\n",
        }) );

        set("force_factor",60);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        
} 
void die(){
         message_vision("$N΢΢һ��������ɫ�ָֻ��˺���\n", this_object());
        "/cmds/imm/full"->main(this_object(),"");
}  
int accept_object(object who, object ob)
{       
        if (!ob->query("marks/֩����˿�")) return 0;
        if (ob->query("name")==HIG"��֦һҶ��"NOR && who->query_temp("eren/kid_result")
                && !who->query("marks/����"))
        {
                command("ah");
                if (!who->query("marks/����")) {
                        who->add("potential",1000);
                        who->add("combat_exp",10000);
                        who->set("marks/����",1);
                        tell_object(who,WHT"�㱻�����ˣ�һǧǱ�ܣ�һ����ֵ��\n"NOR);
                }
                message_vision("$N˵:̫���ˣ�̫���ˡ�\n",this_object());
                return 1;
        }
        return 0;       
} 
/*
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() ){
                return;
        }
        message_vision("$NЦ�������˹���������Ц��������̨Զ�������ˡ���\n", this_object() );
        return;
} 
*/ 
