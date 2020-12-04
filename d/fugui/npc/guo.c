#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("����·", ({ "guo", "guo dalu" }) );
        set("long",
                "����·���󷽵Ĵ���·��·����������������·�Ǹ��ܴ�·���ˡ�\n");
        set("attitude", "heroism");
        create_family("����ɽׯ",7,"����");
        set("reward_npc", 1);
        set("difficulty", 5);
        if (random(3)) set("attitude","friendly");
        set("str",40);
        set("cor",50);
        set("cps",25);
        set("agi",40);
        set("int",40);
        set("per",20);
        set("tol",30);
        set("skill_public",1);
        set("max_neili",1200);
        set("force",1200);
        set("force_factor",70);
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
                
        set("m_success/��ݹ���·",1);
        set("chat_chance",1);
        set("chat_msg", ({
                        "����·˵�������������ѵ����������������Ͳ������첻�����ģ�\n�������������ϳԵ�ѼƤ�¶��Ѿ������ÿ����ˡ���\n",
                                })  );
        
        set("combat_exp", 4000000);
        
    		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // �����ڹ�
	set_skill("huntian-qigong", 380);    // ��������
	set_skill("unarmed", 260);           // ����ȭ��
	set_skill("xianglong-zhang", 380);   // ����ʮ����
	set_skill("dodge", 260);      	     // ��������
	set_skill("xiaoyaoyou", 380);        // ��ң��
	set_skill("parry", 260);             // �����м�
	set_skill("staff", 380);             // ��������
	set_skill("dagou-bang", 380);        // �򹷰���
	set_skill("begging", 380);           // �л�����
	set_skill("checking", 380);          // ����;˵
	set_skill("training", 380);         // Ԧ����
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

        
        set("inquiry",  ([
                "����" : "�����ҹ���·�ĺ��ֵ�,������....��,�Բ�ס��....\n",
                "��̫ƽ" : "�����ҹ���·�ĺ��ֵ�,������....��,�Բ�ס��....\n",
                "����" : "�����ҹ���·�ĺ��ֵ�,������....��,�Բ�ס��....\n",
                "��Ѽ" : "���Ϲ�������ͷ�ӵ���Ѽʵ�ڲ���,ʵ�ڲ���.\n",
                "wangdong" : "�����ҹ���·�ĺ��ֵ�,������....��,�Բ�ס��....\n",
                "lintaiping" : "�����ҹ���·�ĺ��ֵ�,������....��,�Բ�ס��....\n",
                "yanqin" : "�����ҹ���·�ĺ��ֵ�,������....��,�Բ�ס��....\n",
                "kaoya" : "���Ϲ�������ͷ�ӵ���Ѽʵ�ڲ���,ʵ�ڲ���.\n",
                ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        ::init();
       add_action("do_jiebai","jiebai");
} 
void attempt_apprentice(object me)
{
        command("shake");
        command("say �������ķ����ң�����������ͽ��\n");
} 
int accept_object(object who, object ob)
{       
        object jinlian;
        
        if (who->query("m_success/��ݹ���·") )
        { if ((ob->query("name")==HIM"�廨�ɰ�"NOR) && (!who->query("m_success/����·�ɰ�") ))
            {
            	message_vision("����·���źɰ���Ȼ���ˣ���ˮ������ҹ������ˡ���\nȻ����̧��ͷ���������м�������$N���֡�\n",who);
              who->add("combat_exp",8888);
              who->add("potential",3333);
              who->add("score",2222);
              tell_object(who,"\n��ϲ��ϲ���㱻�����ˣ�\n" + chinese_number(8888) + "��ʵս����\n" + chinese_number(3333) + "��Ǳ��\n" + chinese_number(2222)+"���ۺ�����\n");
              who->set("m_success/����·�ɰ�",1);
           	return 1;
            	
            	}else
            	{
            	                 command("shake " + who->query("id"));
            	                 return 0;
            		}
           
        	
        	}
        	else
      {
        
        
        if (ob->query("name")=="����Ů����" && ob->query("liquid/name")=="����Ů����"&& ob->query("liquid/remaining")>100)
        {
                command("shake " + who->query("id"));
                command("say ��Ҳ�о�����ڲ�����������ζ������񫣬����񫣡\n");
           who->set_temp("marks/Ů����",1);
                return 1;
        }
        
        if (ob->query("name")=="���߹�" && ob->query("liquid/name")=="��ƷŮ����" && ob->query("liquid/remaining")>100)
        {
                write("����·�������߹޵���ǣ����Ƶ�����У��з����۾�������¶����\n������顣���ã�����·����һ���������˼伫Ʒ���˼伫Ʒ������\n");
                if (who->query_temp("marks/Ů����"))
                {
                        who->set_temp("marks/���߹�",1);
                        return 1;
                }
                else
                {
                        command("hmm");
                }
                return 1;
        }
        
        if (ob->query("name")=="��Ѽ")
        { 
                who->set_temp("marks/��Ѽ",1);
                write("����·һ�´���������е������������Ϲ����Ѽ������������·����\n����ô�����з�Ѽ��û������������������ѽ��\n");
                return 1;
        }
        
        
        if (ob->query("name")==HIG"��̳"NOR && ob->query("liquid/name")=="��Ҷ��" && ob->query("liquid/remaining")==1500 )
        {
                if (who->query_temp("marks/��Ѽ"))
                {
                        write("����·�����̳����ǣ������۾����������˿�����̾�������ⲻ��\n��������ֱ������������\n");
                        command("pat " + who->query("id"));
                        write("����·��Ц�������ֵܱ��ҹ���·��Ҫ��·���������������鷳�㽻\n���Ҵ��������˵����·�������뻹�ǻ�ɽׯ�ĺã������з����о�\n�ȣ��������Ǽ��������ѣ��ٸ�������Ҳ�����ˡ�\n");
                        who->start_busy(3);
                        jinlian = new(__DIR__"obj/chain");
                        jinlian->move(who);
                        who->set_temp("marks/�õ�����",1);
                        who->delete_temp("marks/��Ѽ");
                        call_out("goback", 3);
                        return 1;
                   }
                else 
                {
                        write("����·��ʱ���۷Ź⣬һ��������������ͷ�λ��Դ�˵�����ô��\n������ӣ���ζ��ƫ�棬ʧ֮���񣬲���񫣬����񫣡\n");
                }
        return 1;
        }
        
        message_vision("$Nɨ��һ��$n���еĶ�����������˵���������ֶ�����������������ˡ���\n",this_object(),this_player());
        return 0;
        }
} 
int goback()
{
        write("����·���۷Ź⣬�����ư�ɨ����ǰ�ķ�Ѽ���ƣ�������ͷ�λ���\n��,һ������δ�������ӡ�\n\n");
        say ("����·˵���������㷹������ȥ���ߣ�˳�����һ���ֵ��ǵ���Ϣ����\n");
        say ("����·�������ˣ����ѴҴ��߳�������֪���١�\n\n");
        destruct( this_object());
        return 1;
} 
int recognize_apprentice(object ob)
{
        if( !ob->query("m_success/��ݹ���·") ){
                command("say ����㹦���������ʲôָ�����㻹�����Ҹ��˰ɣ�\n");
                return 0;
        }
        return 1;
} 
int do_jiebai(string arg)
{
        string guo;
        object me,ob; 
        me = this_player();
        ob = this_object();
        
        if( !arg
        ||      sscanf(arg, "with %s",guo)!=1
        ||      !me)
                return notify_fail("ָ���ʽ: jiebai with <ĳ��>\n");
                
        if( me->query("m_success/��ݹ���·"))  
   {
                message_vision("$N������������$n�����밲���е�������·�ֵܣ���\n", me, ob);
                return 1;
        } 
        if(me->query_temp("marks/���߹�") && me->query("marks/�ȼýٷ�"))
        {
/*              if(time()-(int) me->query("last_time_jiebai_guo") < 1800){
                message_vision("$NЦ��������ô��ô���ֻ����ˣ��������ҿ��ǿ�����˵�\n",ob);
                return 1;
        }
            if ( random(10) ){
                        message_vision("$N����������˵�����ҵÿ��ǿ����پ�����\n",this_object());
                        me->set("last_time_jiebai_guo",time());
                        return 1;
        } 
*/
        message_vision(HIG"$N��Ц���úã����ֶ��˸��ֵܡ��ֽ񽭺�֮����Ϊ����С��ɽ�ƣ���ϧ
������������ؾ���Ϊ�ֵ������֮������С��ɽ���ؾ������������\n"NOR,
                        this_object());
                tell_object(me, HIY"\n����·�������������˵��һͨ���㲻�ɵû�Ȼ����\n"NOR);
                message("vision", "\n����·��"+me->name()+"�������Ｘ�䣬"+me->name()+"���ɵ�������ͷ��\n",
                                environment(me), me); 
                me->set("m_success/��ݹ���·",1);
                message("\n����·��ԥ��һ�£�����˵����Ϊ���Ѿ����뽭���ˣ���֮ǰ��ʧ��һ������Ҫ��Ǯ�������ֵ���Ϊ���ҵ�������\n"+me->name()+"ˬ��ص��˵�ͷ�����ã���\n",
                                environment(me), me); 
                me->add("score",1000);
                return 1;
 
        } else {
                command("hmm");
                message_vision("$Nҡҡͷ����$N�������������ҽ�ݻ�������ġ�\n",this_object());
        }
    return 1;
}      
