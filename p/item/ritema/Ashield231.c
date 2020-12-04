#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[36mŒﬁµ–÷Æ∂‹[2;37;0m", ({ "good shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "√Ê");
		set("long", @LONG
Œﬁµ–÷Æ∂‹[2;37;0m’‚ «“ª√Ê”…Œﬁ±»º·”≤µƒæ´∏÷º”…œ[33m¥Û¬È[2;37;0m÷∆≥…£¨÷ÿ∂˛ΩÔ¡„¡Ω“ª«Æµƒ[36mŒﬁµ–÷Æ∂‹[2;37;0m°£
◊€∫œ∆¿º€[1;34mæŸ ¿∫±º˚[2;37;0m ø¥∆¿¥Œﬁ±»º·πÃ£¨æﬂ”–[34m≤ª¥Ì[2;37;0mµƒ∑¿ª§¡¶£°
…œ√ÊªπøÃ¡À“ª–©∑˚◊÷£∫
º·”≤:[1;35mæ¯ ¿[2;37;0m ÃÏ”Ó:[33m“ª∞„[2;37;0m «…÷∆:[32m¥÷≤⁄[2;37;0m 
ÃÂ¡È:[32m¥÷≤⁄[2;37;0m Õ˛¡¶:[33m“ª∞„[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 9000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",9);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 147);
    set("armor_prop/defense", 30);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 10);

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
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 11);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";