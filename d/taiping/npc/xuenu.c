#include <ansi.h>
#include <command.h>
inherit NPC; 
void create()
{ 
        set_name("Ѫū",({"xuenu"}));
        set("title",YEL"����¥"NOR);
        set("long", "�������ǳ����ŵġ���������һ�����ѡ����Ȳ�������һ�룬Ҳ��������һ�롣��
�ұ߰������ѣ����ú����룬��߰���ȴ�ǳ���ġ����ڶ��ϴ����黷���а����
��Ĩ��֬�ۣ����ϻ��������ͷ��--ֻ���ұߡ�����������������Ǹ�������
Ӥ��������Ц�������紺�磬�����紺���������Ǵ�ˮ��������ò���������ͫ��
���ȴ���紺����");
        set("age",20);
        set("combat_exp", 9000000);
        set("attitude", "friendly");    
        
        set("no_busy",10);
        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",130); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
// set("dungeon_npc","check");
        
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
        
} 
int accept_object(object who, object ob)
{
        if( ob->name()==HIR"��ʯ"NOR) {
                if (!who->query("m_killer/̷����") && !who->query("m_killer/̷�컢")
                        && !who->query("m_killer/̷�챪") && !who->query("parrot/�̿�")){             
                command("say ����Ķ������ĺ�ʯͷ��");
                return 0;
                } 
                call_out("event1",1,who,0);
                who->set("parrot/Ѫū����",1);
                return 1;
        }        
        return 0;
}     
string *event1_msg=     ({
        
        WHT"\n\n  Ѫū����ɫ��Ȼ���ˣ������Ǻ�Ȼ������������һ���ӡ�\n",
        
        WHT"  ���̵ı��ӣ�\n"NOR, 
        GRN"  ���ⲻ��ʯͷ�������ħѪ������������˻���������ڷ����Ц����������
  �Ϻ�Ȼ�������޷������ı仯��\n"NOR, 
        GRN"  ��������Ȼ�����������Ż�Ĳ���ɫ��������촽��ʼŤ����������۲���¶��
  ����ı��顣\n"NOR,
        
        GRN"  ����˫�Ⱥ�˫�ֹؽں�Ȼ����Ť������ʵ�޳������ſ��ˣ�¶���ˡ���\n"NOR, 
        GRN"  ����������Ū�Լ�����ͷ������������������������\n"NOR, 
        HIG"  ����Ȼ���˳������³�һ��Ũ��ɫ�ģ����Ŷ���ĳ�֭��\n"NOR, 
        GRN"  �������������ֱ������������������ŵ�������Ҫ����ʹ������\n"NOR, 
        GRN"  ��������������ֱ������������Ҳͻ�ֱ�ÿ��¶�����\n"NOR, 
        GRN"  �����ֱ��鲻�ϵ��������Ͻ������ţ���������ʱ��������ʱ�ͳ���\n"NOR, 
        GRN"  �Ǿ�����ͬһ�����ܾ��еı��飬Ҳ������ͬһ�����ܷ��ó���������\n"NOR, 
        WHT"  Ȼ������Ȼ��������������ͻȻŤת������Ť������\n"NOR, 
   GRN"  ���ı�����$N����Ҳ����$N�������Ũ֭���ڲ�ͣ��������\n"NOR,
        
        GRN"  �����ﾹȻ��������������Ȼ����˸�������\n"NOR, 
        RED"  ǽ��ͼ���ϵ�Ѫ������ߵ�ʮ��ֻ���񣬾��Ѻ�Ȼ����һֻ��\n"NOR,
        
        WHT"  ��������������������\n"NOR, 
        WHT"  ��������������\n"NOR,
        
        WHT"  ��������\n"NOR, 
        GRN"  ������Խ��Խ�ᣬԽ��Խ����\n"NOR, 
        GRN"  ѪūŤ������Ŀ����֫�𽥻ָ�����������������ȴ����ȫ���ѡ�\n"NOR, 
        GRN"  ���ıǼ������ź���ȫ�������ź���ͫ�������˷ܺ�����Ѷ���ɢ��\n"NOR, 
        GRN"  �����ڲ�ͣ��������Ϣ��Ȼ�������Ͼͺ�Ȼ¶�������۶������΢Ц��\n"NOR, 
        GRN"  ���ڿ���$N����ͣ�ĵ������������ã�����á�����\n"NOR, 
});  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) 
                || this_object()->is_fighting())        return;
        message_vision(event1_msg[count]+"\n",me);
        if(++count==sizeof(event1_msg))
        {
                message_vision(RED"\n\n   �ٿ�ǽ�ϵ�ͼ����Χ����Ѫ�������ԵĹ����Ѿ��ֱ��ʮ��ֻ��\n\n\n"NOR,this_object(),me);
                return;
        }
        else call_out("event1",1,me,count);
        return ;
}  
/*
void init() {
        
        object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}   
*/
