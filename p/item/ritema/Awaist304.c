#include <ansi.h> 
#include <armor.h>

inherit WAIST;

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
	      set_name("[33m¹ã³ÉÖ®Ñü´ø[2;37;0m", ({ "guangcheng waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
		set("long", @LONG
[33m¹ã³ÉÖ®Ñü´ø[2;37;0mÕâÊÇÒ»ÌõÓÉÎÞ±È¼áÓ²µÄ¾«¸Ö¼ÓÉÏ[1;33mÜÑÂé[2;37;0mÖÆ³É£¬ÖØÒ»½ïÁãÁ½ÆßÇ®µÄ[33m¹ã³ÉÖ®Ñü´ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎÞË«[2;37;0m ¿´ÆðÀ´ÎÞ±È¼á¹Ì£¬¾ßÓÐ[36m²»Ð¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ»¹¿ÌÁËÒ»Ð©·û×Ö£º
¼áÓ²:[1;31mÎÞË«[2;37;0m ÌìÁé:[32m´Ö²Ú[2;37;0m ÌìÓî:[36m²»´í[2;37;0m ÇÉÖÆ:[34mÏ¸Ëé[2;37;0m 
ÍþÁ¦:[36m²»´í[2;37;0m 

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
		set("armor_prop/intelligence",36);
		set("armor_prop/strength",19);
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
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 18);

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
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";