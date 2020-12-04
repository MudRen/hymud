#include <ansi.h> 
#include <armor.h>

inherit WRISTS;

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
	      set_name("[34m¹«ºîÖ®»¤Íó[2;37;0m", ({ "gonghou wrists", "wrists" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
		set("long", @LONG
[34m¹«ºîÖ®»¤Íó[2;37;0mÕâÊÇÒ»Ë«ÓÉÎÞ±È¼áÓ²µÄ¾«¸Ö¼ÓÉÏ[1;33mÜÑÂé[2;37;0mÖÆ³É£¬ÖØÁã½ï°ËÁ½¶þÇ®µÄ[34m¹«ºîÖ®»¤Íó[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎÞË«[2;37;0m ¿´ÆðÀ´ÎÞ±È¼á¹Ì£¬¾ßÓÐ[36m²»Ð¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[31m»ð[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;35m·ç[2;37;0m:[33mºÜ¸ß[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ð©·û×Ö£º
¼áÓ²:[1;31m´´ÊÀ[2;37;0m ÌìÓî:[36m²»´í[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
²»ÀÏ:[34mÏ¸Ëé[2;37;0m ÍþÁ¦:[33mºÜ¸ß[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",17);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 74);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 21);
    set("armor_prop/jingli", 21);
    set("armor_prop/damage", 45);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",9);
    set("wtypeE",0);
    set("wtypeF",4);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 14);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";