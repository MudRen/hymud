#include <ansi.h> 
inherit NPC;  
void create()  
{  
 int ni;  
 ni=1+random(36);  
 set_name("�����"+chinese_number(ni)+"��", ({ "qishi"}));  
 set("long", "��Ȼ�����ú���ֻ��������֯����װ����ǰ����һ��  
 ��ͭ���ľ������Ͽ��Ÿ����֡�\n");  
 set("title","�������ǰ����");  
 set("gender", "����");  
 set("age", (30-ni/3));  
 set("attitude", "friendly");  
 set("jing", -500-random(1000));  
 set("str", 30);  
 set("per",28);  
 set_skill("sword",(110-ni));  
// set_skill("deisword",(100-ni));  
// map_skill("sword","deisword"); 
 set("combat_exp", (30000*(36-ni))); 
 setup();  
 carry_object("/clone/weapon/gangjian")->wield();  
 carry_object("/clone/misc/cloth")->wear();  
 }  
  
     
