 inherit NPC;
#include <ansi.h>
#include <mudlib.h>
#include <combat.h> 
mapping chinese_location = ([
                 "baiyun":              "���Ƶ�",
                 "bat":                 "����",
                 "bawang":              "������",
                 "biancheng":           "�߳�",
                 "cave":                "���Ƶ��³�",
                 "chuenyu":             "���ɱ�",
                 "death":               "������",
                 "fy":                  "���Ƴ�",
                 "fywall":              "���Ƴ�",
                 "fycycle":              "���Ƴ�",
                 "ghost":               "����ɽׯ",
                 "guanwai":             "����",
                 "guanyin":             "���",
                 "huangshan":           "��ɽ",
                 "huashan":             "��ɽ",
                 "jinan":               "����",
                 "laowu":               "����",
                 "libie":               "����С��",
                 "loulan":              "�����",
                 "manglin":             "ç��",
                 "oldpine":             "����կ",
                 "palace":              "������",
                 "qianfo":              "ǧ��ɽ",
                 "qianjin":             "ǧ��¥",
                 "qingping":            "��ƽɽׯ",
                 "quicksand":           "��ɳĮ",
                 "resort":              "����ɽׯ",
                 "shanliu":             "ɽ��",
                 "shaolin":             "������",
                 "shenshui":            "��ˮ��",
                 "songshan":            "��ɽ",
                 "taiping":             "̫ƽ��",
                 "taishan":             "̩ɽ",
                 "taoguan":             "���幬",
                 "taoyuan":             "��Դ",
            "tieflag":             "����Ȼ��߳�����",
                 "wanmei":              "��÷ɽׯ",
                 "wolfmount":           "��ɽ",
                 "wudang":              "�䵱ɽ",
                 "xinjiang":            "�½�",
                 "yinghe":              "����ڤ��",
                 "yingou":              "�����ĳ�",
                 "zhaoze":              "�������",   
]); 
int verify_item(object item, string arg); 
void create()
{
        set_name("������", ({ "tudi" }) );
        set("title", YEL"������֪ ��������"NOR);
        set("gender", "����" );
        set("cor",20);
        set("age", 68);
        set("str",20);
        set("per",40);
        set("long","
�������ڷ������Ѿ�������ʮ�����ˣ�����������֪�����£���������
û�������ˡ��������ʲô����Ҫ����������������(question)����
ע�⣬��myquest�⣬����ѯ�ʵ�һ�������ġ�
���������ɫ�ģ����ɫ�ʴ��롣
$BLK$ - ��ɫ            $NOR$ - �ָ�������ɫ
$RED$ - ��ɫ            $HIR$ - ����ɫ
$GRN$ - ��ɫ            $HIG$ - ����ɫ
$YEL$ - ����ɫ          $HIY$ - ��ɫ
$BLU$ - ����ɫ          $HIB$ - ��ɫ
$MAG$ - ǳ��ɫ          $HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ          $HIC$ - ����ɫ
$WHT$ - ǳ��ɫ          $HIW$ - ��ɫ 
������question $HIY$�������$NOR$
====�����������ش���"HIY"�������"NOR"�����ڡ�
      question myquest
====�����������ش����Լ���Quest�����    
\n");
        set("combat_exp", 24000000);
        set("attitude", "friendly");
        set("chat_chance",1);
           set("chat_msg",({
                CYN"\n�������ͳ�һ�˺��̴��������س��˼��£�������������˿�����\n\n"NOR,
        }) );  
                        
        set_skill("hammer",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("unarmed",200);
                
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init() {
        add_action("do_ask","question");
}  
int do_ask(string arg) { 
        object *item,me,env;
        string location,*e_location,spot;
        int i,j;
        
        me=this_player();
        
        if (!arg||arg=="")
                return notify_fail("�������ʲô��\n\n");
        
        if (this_object()->query("inquiry_time")+2>time())
                return notify_fail("������˵�����ȵȣ����Ҵ�������˵����\n");
                
        if (arg=="myquest")
        if (!arg=me->query("quest/quest"))
                return notify_fail("������û������\n");       
                
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
   arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        
        
        
        message_vision("$N��$n����"+arg+NOR"�����ڡ�\n",me,this_object());
                
        this_object()->set("inquiry_time",time());     
        item = filter_array(objects(), (: verify_item($1,$2) :) , arg);
        if (sizeof(item)<1) {
                message_vision(CYN"�����س�����ã�̾�˿���˵�����Һ���û����˵���������������������ǰ
�ˣ�ǰ������ɳ̲�ϣ����ˣ��ﲻ�����æ�ˡ���\n"NOR,this_object());
                return 1;
        }
        
/*      message_vision("total is "+(string)sizeof(item)+"\n",me);
        
        for (i=0;i<sizeof(item)-1;i++){
                if (objectp(item[i]) && objectp(environment(item[i]))) 
                        message_vision((string)i+" is "+(string)(environment(item[i])->query("name"))+"\n",me);
        }*/
        
        spot = domain_file(file_name(item[0]));
        
        if (!item[0]->is_character())
        for (i=0;i<sizeof(item)-1;i++) {
                if (!objectp(item[i])) continue;
                env=environment(item[i]);
                if (!objectp(env)) continue;
                if (userp(env)) continue;
                if (env->is_character() && !env->is_corpse()) {
                        spot = domain_file(file_name(env));
//                      message_vision(" is in NPC"+(string)(i)+"\n",me);
                        break; 
           }
                spot = domain_file(file_name(item[i]));
        }       
                
        e_location = keys(chinese_location);
        if (member_array(spot,e_location)==-1) {
                message_vision(CYN"�����ؿ��˼����˵�����ҿ϶���������ϧ�벻�����ˡ���\n"NOR,me);
                return 1;
        }
        message_vision(CYN"����������$N���Դ�˵��ȥ"+chinese_location[spot]+"�������Ұɡ�\n"NOR,me);
        return 1;
}  
int verify_item(object item,string arg) {
        if ( item->query("name")==arg)  return 1;
        return 0;
} 
int attack() {
        command("say �����ɹ󣬲�Ҫ��Ѱ��·��");
        filter_array(this_object()->query_enemy(),(: $1->unconcious() :));
        this_object()->remove_all_killer();
}  
void unconcious() {
        int gin,kee,sen;
        gin =(int)query("max_jing");
        kee =(int)query("max_qi");
        sen =(int)query("max_sen");
        set("eff_qi",kee);set("qi",kee);
        set("eff_jing",gin);set("jing",gin);
        set("eff_sen",sen);set("sen",sen);
        return ; 
} 
void die() {
        int gin,kee,sen;
        gin =(int)query("max_jing");
        kee =(int)query("max_qi");
        sen =(int)query("max_sen");
        set("eff_qi",kee);set("qi",kee);
        set("eff_jing",gin);set("jing",gin);
        set("eff_sen",sen);set("sen",sen);
        return ; 
}    
