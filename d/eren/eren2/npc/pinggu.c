#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
//      set("title","��������");
//      set("nickname","Ц��ص�");
        set("long", "һ��ʮ�߰������Ů����Ȼ����ũ�����Σ�ȴ�ڲ�ס����֮ɫ�����ǣ�
�����۽��ܴ��ŵ����İ��ˡ�\n");
        set("attitude", "friendly");
        set("combat_exp", 2000000);
                        
        set("max_atman",800);
        set("atman",800);
        set("max_mana", 800);
        set("mana", 800);
        set("max_neili",1000);
        set("neili",1000);
                
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("inquiry", ([
                "С��" : "С�̺���ͼ������������ֱ���",
                 "ŷ��������" : "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ŷ����" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ŷ����" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ouyang ding" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "ouyang dang" :  "ŷ������������Խ��Խ�ã���ǹ�������¥�ˡ�",
                "������¥": "������¥��Ȼ�ǹ���������ඣ���˵���������ⲻ�ã�����Ϊԭ�Ϸ����ء�",
                "������ջ": "������ջ����������Ů�����ġ�",
                "��С��": "������ջ����������Ů����С�����ġ�",
                "���˹�": "�����Ƕ��ܹ��ˣ�����˹���������û�����ˡ�",
                "������": "�����������˭�˲��������ﻹ�����������ء�",
                "����": "����ҽ����������֮�ܡ�",
                "���ϵ�": "���ϵ�ר��������˵Ҫ�����İ���������ѧ������������С�",
                "��ԯ����": "�����ֻʣ���Ǽ䵱���ˡ�",
                "�����": "�������ҵ����ҵ����Һܺã���������µ�̩ɽȥ�ˡ�",                   
           ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��Ƽ��˵����������ҵ����ͽ�����ؼҰɡ���\n",
        }) );

        set_name("��Ƽ��",({"tie pinggu","pinggu"}));
        set("age",18);
        set("gender","Ů��");
        set("force_factor",40);
        setup();
        carry_object(__DIR__"obj/pgcloth")->wear();
        
} 
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
        if (ob->query("marks/�Ⱥ�֩��") && !ob->query("marks/֩����˿�")) {
                message_vision(CYN"$N˵��̫лл����˺�֩�룬������ת���㣬�˵������Ļ��ϲ⣬Ψ��ҽ��
����������ʽ�������"NOR+HIR"��������"NOR+CYN"֮�ܡ���\n"NOR, this_object(),ob);
                ob->set("marks/֩����˿�",1);
           }
        return;
}   
