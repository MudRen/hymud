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
	      set_name("[1;37m¿ñÀÇÖ®ÊÖÌ×[2;37;0m", ({ "good hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸±");
		set("long", @LONG
¿ñÀÇÖ®ÊÖÌ×[2;37;0mÕâÊÇÒ»¸±ÓÉ·Ç³£¼áÓ²µÄ[31mÁ÷»¨Ê¯[2;37;0m¼ÓÉÏ[33mÑÇÂé[2;37;0mÖÆ³É£¬ÖØÎå½ï¾ÅÁ½ÈıÇ®µÄ[1;37m¿ñÀÇÖ®ÊÖÌ×[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;34m¾ÙÊÀº±¼û[2;37;0m ¿´ÆğÀ´·Ç³£¼á¹Ì£¬¾ßÓĞ[36mÒ»°ã[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [33mÍÁ[2;37;0m:[35m±ê×¼[2;37;0m [1;37mÀ×[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;34mµç[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;32mÄ§Íõ[2;37;0m ÌìÁé:[36m²»´í[2;37;0m ¸£Ô´:[36m²»´í[2;37;0m 
ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
ÌåÁé:[36m²»´í[2;37;0m ³¤Éú:[36m²»´í[2;37;0m ÍşÁ¦:[36m²»´í[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m´óÏÈÉú[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m¸«·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wxswlh");
		set("ownername", "´óÏÈÉú");
		set("value", 9000);
		set("armor_prop/intelligence",18);
		set("armor_prop/strength",32);
		set("armor_prop/karey",13);
		set("armor_prop/percao",40);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 32);
    set("armor_prop/parry", 8);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 941);
    set("armor_prop/defense", 18);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 17);
    set("armor_prop/jing", 16);
    set("armor_prop/jingli", 24);
    set("armor_prop/damage", 688);

    set("wtypeA",10);
    set("wtypeB",3);
    set("wtypeC",2);
    set("wtypeD",1);
    set("wtypeE",5);
    set("wtypeF",0);
    set("wtypeG",8);
    set("wtypeH",8);
    set("wtypeI",5);
    set("wtypeJ",0);
    set("wtypeK",2);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";