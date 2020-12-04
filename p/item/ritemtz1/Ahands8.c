#include <ansi.h> 
#include <armor.h>

inherit HANDS;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[31mÊ¤Ð°Ö®ÊÖÌ×[2;37;0m¡ï", ({ "shengxie hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸±");
		set("long", @LONG
[31mÊ¤Ð°ÍþÁ¦¾Þ´ó¶øÎÞÈÎºÎÒªÇó£¡
[2;37;0mÕâÊÇÒ»¸±ÓÉ¼«Æä¼áÓ²µÄ¾«¸Ö¼ÓÉÏ[1;33mÄ¾ÃÞ»¨[2;37;0mÖÆ³É£¬ÖØÒ»½ïËÄÁ½ÆßÇ®µÄ[31mÊ¤Ð°Ö®ÊÖÌ×[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃðµØ[2;37;0m ¿´ÆðÀ´¼«Æä¼á¹Ì£¬¾ßÓÐ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ»¹¿ÌÁËÒ»Ð©·û×Ö£º
¼áÓ²:[1;33mÃðÊÀ[2;37;0m ¾ø´ú:[33mºÜ¸ß[2;37;0m ÇÉÖÆ:[35m±ê×¼[2;37;0m 
°×Ê¯:[33mºÜ¸ß[2;37;0m ÉÁµç:[35m±ê×¼[2;37;0m 
ÍþÁ¦:[31m¾«ÖÂ[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",46);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 42);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 59);


    set("armor_prop/armor", 147);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 292);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 25);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";