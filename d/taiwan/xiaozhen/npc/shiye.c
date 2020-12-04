inherit NPC;
void create()
{
   set_name("梁师爷",({"liang shiye","liang","shiye","liangshiye"}));
   set("gender","男性");
   set("age",54);
   set("mingwang",-1000);
   set("long","梁师爷算法精通,对于穷人是绝不客气的!\n");
   set("combat_exp",700000);
   set("max_force",700);
   set("force",700);
   set("force_factor",20);
   set("chat_chance",10);
   set("chat_msg",({
        "梁师爷用食指沾了点茶水,把自己的两撇鼠须上抹了一遍!\n",
        "梁师爷翻开帐簿,一只手夹着支毛笔,劈里啪啦打起算盘来!\n",
        "梁师爷端起小茶壶,美滋滋得喝了口茶!\n",
        "梁师爷嘴里哼着二皮小调,一边飞快地翻着帐簿!\n",
   }));
  set_skill("unarmed",120);
  set_skill("literate",120);
  set_skill("dodge",120);
  set_skill("parry",120);
  set_skill("force",120);
  setup();
  carry_object("/clone/misc/cloth")->wear();
  add_money("gold",1);
}
  