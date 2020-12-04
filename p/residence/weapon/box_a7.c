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
	      set_name("[1;31mÁ¶ÓüÖ®ÊÖÌ×[2;37;0m", ({ "lianyu hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸±");
		set("long", @LONG
[1;31mÈıÊ®ÈıÌìÏÂÓĞµØ£¬µØÏÂÓĞ³Ç£¬³ÇÃû¹í³Ç£¬´óĞ¡ÑıÄ§£¬ÈËÉñĞóÉú¶¼ÔÚ´ËÂÖ»ØÍù·µ£¬Î½Ö®¡°Á¶Óü¡±£¡
[2;37;0mÕâÊÇÒ»¸±ÓÉÎŞ±È¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØËÄ½ïÎåÁ½ÎåÇ®µÄ[1;31mÁ¶ÓüÖ®ÊÖÌ×[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [36mÄ¾[2;37;0m:[1;32mÄ§Íõ[2;37;0m [32mË®[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ¾ø´ú:[34mÏ¸Ëé[2;37;0m ÇÉÖÆ:[35m±ê×¼[2;37;0m 
×ÏÊ¯:[35m±ê×¼[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 
³¤Éú:[35m±ê×¼[2;37;0m ÍşÁ¦:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÍò½£´©ĞÄ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m°µÆ÷[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "box");
		set("ownername", "Íò½£´©ĞÄ");
		set("value", 25000);
		set("armor_prop/intelligence",32);
		set("armor_prop/strength",32);
		set("armor_prop/karey",0);
		set("armor_prop/percao",25);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",32);
    set("armor_prop/dodge", 48);
    set("armor_prop/parry", 52);
    set("armor_prop/attack", 49);


    set("armor_prop/armor", 750);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 32);
    set("armor_prop/qi", 53);
    set("armor_prop/jing", 40);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 1232);

    set("wtypeA",10);
    set("wtypeB",9);
    set("wtypeC",8);
    set("wtypeD",5);
    set("wtypeE",8);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",4);
    set("wtypeJ",4);
    set("wtypeK",4);
    set("wtypeL",5);
    
    
                set("skill", ([
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";